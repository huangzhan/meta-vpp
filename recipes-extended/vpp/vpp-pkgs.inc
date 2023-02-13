PACKAGES =+ "libvppinfra libvppinfra-dev vpp-plugin-dpdk vpp-plugin-core python3-vpp-api"

FILES:${PN} = " \
	${sysconfdir}/sysctl.d/ \
	${sysconfdir}/vpp/ \
	${datadir}/vpp/api/core/ \
	${systemd_system_unitdir}/vpp.service \
	${bindir}/vpp \
	${bindir}/vat2 \
	${bindir}/vpp_echo \
	${bindir}/vpp_get_stats \
	${bindir}/vpp_prometheus_export \
	${bindir}/vppctl \
	${bindir}/svmdbtool \
	${bindir}/svmtool \
	${bindir}/vpp_api_test \
	${bindir}/vpp_get_metrics \
	${bindir}/vpp_restart \
	${libdir}/libvcl_ldpreload.so.${PV} \
	${libdir}/libvlibmemoryclient.so.${PV} \
	${libdir}/libvppmem_preload.so.${PV} \
	${libdir}/libvppcom.so.${PV} \
	${libdir}/libvatplugin.so.${PV} \
	${libdir}/libvppapiclient.so.${PV} \
	${libdir}/libvatclient.so.${PV} \
	${libdir}/libvapiclient.so.${PV} \
	${libdir}/libsvmdb.so.${PV} \
	${libdir}/libvlibmemory.so.${PV} \
	${libdir}/libnat.so.${PV} \
	${libdir}/libvlib.so.${PV} \
	${libdir}/libsvm.so.${PV} \
	${libdir}/libvnet.so.${PV} \
	"
FILES:${PN}-plugin-core = " \
			${libdir}/vpp_plugins/ \
			${libdir}/vat2_plugins/ \
			${libdir}/vpp_api_test_plugins/ \
			${datadir}/vpp/api/plugins/ "

FILES:${PN}-plugin-dpdk = " ${libdir}/vpp_plugins/dpdk_plugin.so"
FILES:libvppinfra = " ${libdir}/libvppinfra.so.${PV} "
FILES:libvppinfra-dev = " ${includedir}/vppinfra/* \
			${libdir}/libvppinfra.so "
FILES:python3-vpp-api = " ${PYTHON_SITEPACKAGES_DIR}/* "

FILES:${PN}-dev = " \
		${includedir}/* \
		${bindir}/vapi_c_gen.py \
		${bindir}/vapi_cpp_gen.py \
		${bindir}/vapi_json_parser.py \
		${bindir}/vppapigen \
		${datadir}/vpp/*.py \
		${datadir}/vpp/api/plugins/ \
		${libdir}/cmake/vpp \
		${libdir}/libvppmem_preload.so \
		${libdir}/libvatclient.so \
		${libdir}/libnat.so \
		${libdir}/libvcl_ldpreload.so \
		${libdir}/libvppapiclient.so \
		${libdir}/libvppcom.so \
		${libdir}/libvlib.so \
		${libdir}/libsvm.so \
		${libdir}/libsvmdb.so \
		${libdir}/libvatplugin.so \
		${libdir}/libvlibmemory.so \
		${libdir}/libvapiclient.so \
		${libdir}/libvnet.so \
		${libdir}/libvlibmemoryclient.so "
