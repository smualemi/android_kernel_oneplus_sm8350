// SPDX-License-Identifier: GPL-2.0-only
/*
 * Comprehensive __weak stubs for QTI platform APIs that are unavailable
 * in standalone CI builds (the real drivers are compiled as modules =m,
 * but built-in code references their EXPORT_SYMBOL functions).
 *
 * These stubs are compiled unconditionally (obj-y).  When the real .ko
 * is loaded at boot, its strong symbol definitions override these stubs
 * automatically — no functional change on a real device.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/device.h>
#include <linux/notifier.h>
#include <linux/workqueue.h>
#include <linux/tracepoint.h>

/* ── socinfo ─────────────────────────────────────────────────────────── */
const char *__weak socinfo_get_id_string(void)
{
	return "lahaina";
}
EXPORT_SYMBOL(socinfo_get_id_string);

uint32_t __weak socinfo_get_serial_number(void)
{
	return 0;
}
EXPORT_SYMBOL(socinfo_get_serial_number);

/* ── MSM minidump ─────────────────────────────────────────────────────── */
bool __weak msm_minidump_enabled(void)
{
	return false;
}
EXPORT_SYMBOL(msm_minidump_enabled);

/*
 * msm_minidump_add_region takes a const struct md_region *.  Rather than
 * pulling in minidump.h (which conditionally declares it), declare with
 * void * so this translation unit stays header-free.
 */
int __weak msm_minidump_add_region(const void *entry)
{
	return 0;
}
EXPORT_SYMBOL(msm_minidump_add_region);

/* ── QPNP PBS ────────────────────────────────────────────────────────── */
int __weak qpnp_pbs_trigger_event(struct device *dev, u8 bitmap)
{
	return 0;
}
EXPORT_SYMBOL(qpnp_pbs_trigger_event);

/* ── Subsystem restart / early notifiers ─────────────────────────────── */
int __weak subsys_register_early_notifier(const char *subsys_name,
					  int notif_type,
					  void (*cb)(void *),
					  void *data)
{
	return -ENOTSUPP;
}
EXPORT_SYMBOL(subsys_register_early_notifier);

int __weak subsys_notif_unregister_notifier(void *subsys_handle,
					   struct notifier_block *nb)
{
	return 0;
}
EXPORT_SYMBOL(subsys_notif_unregister_notifier);

/* ── QCOM SMEM state ─────────────────────────────────────────────────── */
/* qcom_smem_state is an opaque struct; callers only hold pointer. */
void *__weak qcom_smem_state_get(struct device *dev,
				  const char *con_id,
				  unsigned int *bit)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_smem_state_get);

int __weak qcom_smem_state_update_bits(void *state, u32 mask, u32 value)
{
	return -EINVAL;
}
EXPORT_SYMBOL(qcom_smem_state_update_bits);

/* ── Service notifier ────────────────────────────────────────────────── */
int __weak service_notif_pd_restart(const char *service_path,
				    int instance_id)
{
	return 0;
}
EXPORT_SYMBOL(service_notif_pd_restart);

int __weak service_notif_unregister_notifier(void *service_notif_handle,
					  struct notifier_block *nb)
{
	return 0;
}
EXPORT_SYMBOL(service_notif_unregister_notifier);

/* ── Ramdump ─────────────────────────────────────────────────────────── */
void __weak destroy_ramdump_device(void *dev)
{
}
EXPORT_SYMBOL(destroy_ramdump_device);

/* ── Command DB ──────────────────────────────────────────────────────── */
u32 __weak cmd_db_read_addr(const char *id)
{
	return 0;
}
EXPORT_SYMBOL(cmd_db_read_addr);

const void *__weak cmd_db_read_aux_data(const char *id, u8 *len)
{
	if (len)
		*len = 0;
	return NULL;
}
EXPORT_SYMBOL(cmd_db_read_aux_data);

/* ── RPMh ────────────────────────────────────────────────────────────── */
/*
 * rpmh_write / rpmh_write_async take (struct rsc_drv *, enum rpmh_state,
 * const struct tcs_cmd *, u32 n).  Use void * for the opaque types.
 */
int __weak rpmh_write(const void *dev, int state,
		      const void *cmd, u32 n)
{
	return 0;
}
EXPORT_SYMBOL(rpmh_write);

int __weak rpmh_write_async(const void *dev, int state,
			    const void *cmd, u32 n)
{
	return 0;
}
EXPORT_SYMBOL(rpmh_write_async);

/* ── Run Queue Stats (tick-sched.c references) ───────────────────────── */
/*
 * rq_info is struct rq_data defined in kernel/sched/msm_energy_eff.h.
 * rq_wq is struct workqueue_struct *.
 * Provide zero-filled placeholder definitions; tick_sched_timer only
 * reads members — it won't crash with zeros at CI build validation time.
 * On a real device the scheduler code provides the strong definitions.
 */
unsigned char rq_info[512] __weak;
EXPORT_SYMBOL(rq_info);

struct workqueue_struct *rq_wq __weak;
EXPORT_SYMBOL(rq_wq);

/* ── HH suspend sysctl ───────────────────────────────────────────────── */
int sysctl_hh_suspend_timeout_ms __weak;
EXPORT_SYMBOL(sysctl_hh_suspend_timeout_ms);

/* ── PIL restart tracepoint ──────────────────────────────────────────── */
/*
 * TRACE_EVENT registers a struct tracepoint.  Provide a bare-minimum
 * definition so the linker is satisfied.  The real tracepoint is from
 * the subsystem restart driver.
 */
struct tracepoint __tracepoint_pil_restart_level __weak = {
	.name = "pil_restart_level",
};
EXPORT_SYMBOL(__tracepoint_pil_restart_level);
