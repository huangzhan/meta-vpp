
DPDK_CPU_CFLAGS  = "-pie -fPIC"
# DPDK_TARGET_MACHINE = "nhm"
EXTRA_OEMESON =+ " -Ddefault_library=shared "

do_compile:prepend () {
	export CPU_CFLAGS="${DPDK_CPU_CFLAGS}"
}

