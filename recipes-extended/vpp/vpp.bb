DESCRIPTION = "Vector Packet Processing"

STABLE = "stable/2210"
BRANCH = "master"
SRCREV = "b807f08d87c1186027bb1266dbd41857d9fcb91a"
SRC_URI[sha256sum] = "7281b2eb1c4ae0d55b4f740f1d3475bd709d7f0d307235d344c7975a8353e648"
S = "${WORKDIR}/git"
PV = "22.10"

LICENSE = "Apache-2.0"

LIC_FILES_CHKSUM = "file://LICENSE;md5=175792518e4ac015ab6696d16c4f607e"

AUTOTOOLS_SCRIPT_PATH = "${S}/src"


SRC_URI = "git://github.com/FDio/vpp.git;protocol=https;branch=${STABLE} \
	"
DEPENDS = "dpdk openssl numactl ${PYTHON_PN}-ply-native"

inherit cmake systemd
inherit pkgconfig
inherit python3targetconfig python3-dir

OECMAKE_SOURCEPATH = "${S}/src"
EXTRA_OECONF = " \
	--disable-dependency-tracking \
	--with-log2-cache-line-bytes=6  \
	--srcdir=${S}/src \
	--enable-perftool \
	--disable-papi \
	--disable-japi \
	--disable-static \
	"
EXTRA_OECMAKE = " \
	-DVPP_SET_RPATH=OFF \
	-DVPP_USE_SYSTEM_DPDK=ON \
	"

include vpp-pkgs.inc


do_configure:append () {
	( cd ${B} &&  mkdir -p vppinfra vpp/app )
}

do_install:append () {
	mkdir -p ${D}/etc/vpp
	cp ${S}/src/vpp/conf/startup.conf ${D}/etc/vpp/startup.conf
}

pkg_postinst_ontarget:${PN} () {
echo vm.nr_hugepages=1024 >> /etc/sysctl.conf

# Must be greater than or equal to (2 * vm.nr_hugepages).
echo  vm.max_map_count=3096 >> /etc/sysctl.conf

# All groups allowed to access hugepages
echo vm.hugetlb_shm_group=0 >> /etc/sysctl.conf

# Shared Memory Max must be greator or equal to the total size of hugepages.
# For 2MB pages, TotalHugepageSize = vm.nr_hugepages * 2 * 1024 * 1024
# If the existing kernel.shmmax setting  (cat /sys/proc/kernel/shmmax)
# is greater than the calculated TotalHugepageSize then set this parameter
# to current shmmax value.
echo kernel.shmmax=2147483648 >> /etc/sysctl.conf
	
# And add to rc.local
echo mkdir -p /var/log/vpp >> /etc/rc.local
echo "/usr/bin/vpp -c /etc/vpp/startup.conf" >> /etc/rc.local
chmod 755 /etc/rc.local
}
