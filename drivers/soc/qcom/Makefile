# SPDX-License-Identifier: GPL-2.0
obj-$(CONFIG_QTI_CRYPTO_COMMON) += crypto-qti-common.o
obj-$(CONFIG_QTI_CRYPTO_TZ) += crypto-qti-tz.o
obj-$(CONFIG_QTI_CRYPTO_VIRTUALIZATION) += crypto-qti-virt.o
obj-$(CONFIG_QTI_HW_KEY_MANAGER) += hwkm.o crypto-qti-hwkm.o
obj-$(CONFIG_QCOM_WDT_CORE) += qcom_wdt_core.o
obj-$(CONFIG_QCOM_SOC_WATCHDOG) += qcom_soc_wdt.o
obj-$(CONFIG_MSM_HAB) += hab/
obj-$(CONFIG_QCOM_HGSL) += hgsl/
obj-$(CONFIG_SDX_EXT_IPC) += sdx_ext_ipc.o
ifdef CONFIG_DEBUG_FS
obj-$(CONFIG_MSM_RPM_SMD)   +=  rpm-smd-debug.o
endif
obj-$(CONFIG_QTI_SYS_PM_VX) += sys_pm_vx.o
obj-$(CONFIG_ICNSS2) += icnss2/
obj-$(CONFIG_QTI_PLH_SCMI_CLIENT) += plh_scmi.o
obj-$(CONFIG_QCOM_SYSMON_SUBSYSTEM_STATS) += sysmon_subsystem_stats.o
obj-$(CONFIG_QTI_HW_MEMLAT_SCMI_CLIENT)	+= memlat_scmi.o
obj-$(CONFIG_QTI_HW_MEMLAT) += rimps_memlat.o
obj-$(CONFIG_QTI_HW_MEMLAT_LOG)	+= rimps_log.o
obj-$(CONFIG_QCOM_QFPROM_SYS) += qfprom-sys.o
obj-$(CONFIG_RENAME_BLOCK_DEVICE) += rename_block_device.o
obj-$(CONFIG_QCOM_ADSP_MANUAL_VOTE) += adsp_vote_qmi.o adsp_lpm_voting_v01.o
obj-$(CONFIG_MSM_SLATECOM) += slatecom_spi.o
obj-$(CONFIG_MSM_SLATECOM_INTERFACE) += slatecom_interface.o
obj-$(CONFIG_QCOM_AOP_SET_DDR) += aop-set-ddr.o
obj-$(CONFIG_CPU_V7) += idle-v7.o
obj-$(CONFIG_DUMP_XBL_LOG) += dump_boot_log.o
obj-$(CONFIG_QCOM_CX_IPEAK) += cx_ipeak.o

# GNSS driver
obj-$(CONFIG_GNSS_SIRF)		+= gnsssirf/
obj-$(CONFIG_MSM_SEB) += slate_events_bridge.o
obj-$(CONFIG_MSM_SEB_RPMSG) += slate_events_bridge_rpmsg.o

# Weak stubs for OPlus display notifier APIs (msm_drm_*, lcdinfo_*).
# Required when building without OPlus's proprietary techpack/display fork.
obj-y += oplus_display_stubs.o

# Comprehensive weak stubs for QTI platform APIs unavailable in standalone
# CI builds (socinfo, minidump, rpmh, cmd-db, smem_state, ramdump, etc.).
# __weak symbols are overridden by the real driver modules at runtime.
obj-y += oplus_platform_stubs.o
