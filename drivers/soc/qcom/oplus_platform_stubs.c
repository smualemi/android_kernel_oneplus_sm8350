// SPDX-License-Identifier: GPL-2.0-only
/*
 * Comprehensive __weak stubs for QTI / OPlus platform APIs that are
 * unavailable in standalone CI builds.
 *
 * These symbols are provided by drivers that are either:
 *   a) disabled in the defconfig (# CONFIG_X is not set), or
 *   b) compiled only as loadable modules (=m) with their symbols
 *      therefore not available to vmlinux built-in code.
 *
 * The __weak attribute lets the real driver's strong definition win at
 * link time when the driver IS compiled in. On a real device the modules
 * load from the vendor partition and provide all strong definitions anyway.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/device.h>
#include <linux/notifier.h>
#include <linux/workqueue.h>
#include <linux/tracepoint.h>
#include <linux/err.h>

/* ── socinfo ─────────────────────────────────────────────────────────── */
const char *__weak socinfo_get_id_string(void) { return "lahaina"; }
EXPORT_SYMBOL(socinfo_get_id_string);

uint32_t __weak socinfo_get_serial_number(void) { return 0; }
EXPORT_SYMBOL(socinfo_get_serial_number);

/* ── MSM minidump ────────────────────────────────────────────────────── */
bool __weak msm_minidump_enabled(void) { return false; }
EXPORT_SYMBOL(msm_minidump_enabled);

int __weak msm_minidump_add_region(const void *entry) { return 0; }
EXPORT_SYMBOL(msm_minidump_add_region);

int __weak msm_minidump_remove_region(const void *entry) { return 0; }
EXPORT_SYMBOL(msm_minidump_remove_region);

int __weak do_minidump(void) { return 0; }
EXPORT_SYMBOL(do_minidump);

int __weak msm_dump_data_register_nominidump(void *table_type, void *entry)
{ return 0; }
EXPORT_SYMBOL(msm_dump_data_register_nominidump);

/* ── Ramdump ─────────────────────────────────────────────────────────── */
void *__weak create_ramdump_device(const char *dev_name, void *parent)
{ return NULL; }
EXPORT_SYMBOL(create_ramdump_device);

void __weak destroy_ramdump_device(void *dev) {}
EXPORT_SYMBOL(destroy_ramdump_device);

int __weak do_ramdump(void *dev, void *segs, int n) { return -ENODEV; }
EXPORT_SYMBOL(do_ramdump);

int __weak do_elf_ramdump(void *dev, void *segs, int n) { return -ENODEV; }
EXPORT_SYMBOL(do_elf_ramdump);

/* ── Subsystem restart / PIL ─────────────────────────────────────────── */
void *__weak subsystem_get(const char *name) { return NULL; }
EXPORT_SYMBOL(subsystem_get);

void *__weak subsystem_get_with_fwname(const char *name, const char *fw)
{ return NULL; }
EXPORT_SYMBOL(subsystem_get_with_fwname);

void __weak subsystem_put(void *handle) {}
EXPORT_SYMBOL(subsystem_put);

int __weak subsystem_restart_dev(void *dev) { return -ENODEV; }
EXPORT_SYMBOL(subsystem_restart_dev);

void __weak subsystem_crashed(const char *name) {}
EXPORT_SYMBOL(subsystem_crashed);

void __weak subsys_set_crash_status(void *dev, int crashed) {}
EXPORT_SYMBOL(subsys_set_crash_status);

void *__weak subsys_register(const void *desc) { return ERR_PTR(-ENODEV); }
EXPORT_SYMBOL(subsys_register);

void __weak subsys_unregister(void *handle) {}
EXPORT_SYMBOL(subsys_unregister);

/* ── Subsystem notifier ───────────────────────────────────────────────── */
void *__weak subsys_notif_register_notifier(const char *subsys_name,
					    void *nb)
{ return NULL; }
EXPORT_SYMBOL(subsys_notif_register_notifier);

int __weak subsys_notif_unregister_notifier(void *subsys_handle, void *nb)
{ return 0; }
EXPORT_SYMBOL(subsys_notif_unregister_notifier);

int __weak subsys_register_early_notifier(const char *subsys_name,
					  int notif_type,
					  void (*cb)(void *), void *data)
{ return -ENOTSUPP; }
EXPORT_SYMBOL(subsys_register_early_notifier);

int __weak subsys_unregister_early_notifier(const char *subsys_name,
					    int notif_type)
{ return -ENOTSUPP; }
EXPORT_SYMBOL(subsys_unregister_early_notifier);

/* ── Service notifier / locator ──────────────────────────────────────── */
void *__weak service_notif_register_notifier(const char *service_path,
					     int instance_id,
					     void *data, void *cb)
{ return NULL; }
EXPORT_SYMBOL(service_notif_register_notifier);

int __weak service_notif_unregister_notifier(void *service_notif_handle,
					     void *nb)
{ return 0; }
EXPORT_SYMBOL(service_notif_unregister_notifier);

int __weak service_notif_pd_restart(const char *service_path, int instance_id)
{ return 0; }
EXPORT_SYMBOL(service_notif_pd_restart);

void *__weak get_service_location(void *cb_info) { return NULL; }
EXPORT_SYMBOL(get_service_location);

/* ── QCOM SMEM ───────────────────────────────────────────────────────── */
void *__weak qcom_smem_get(unsigned int host, unsigned int item, size_t *size)
{ return ERR_PTR(-ENODEV); }
EXPORT_SYMBOL(qcom_smem_get);

int __weak qcom_smem_alloc(unsigned int host, unsigned int item, size_t size)
{ return -ENODEV; }
EXPORT_SYMBOL(qcom_smem_alloc);

phys_addr_t __weak qcom_smem_virt_to_phys(void *p) { return 0; }
EXPORT_SYMBOL(qcom_smem_virt_to_phys);

/* ── QCOM SMEM state ──────────────────────────────────────────────────  */
void *__weak qcom_smem_state_get(struct device *dev, const char *con_id,
				 unsigned int *bit)
{ return NULL; }
EXPORT_SYMBOL(qcom_smem_state_get);

int __weak qcom_smem_state_update_bits(void *state, u32 mask, u32 value)
{ return -EINVAL; }
EXPORT_SYMBOL(qcom_smem_state_update_bits);

/* ── RPMh ────────────────────────────────────────────────────────────── */
int __weak rpmh_write(const void *dev, int state, const void *cmd, u32 n)
{ return 0; }
EXPORT_SYMBOL(rpmh_write);

int __weak rpmh_write_async(const void *dev, int state,
			    const void *cmd, u32 n)
{ return 0; }
EXPORT_SYMBOL(rpmh_write_async);

int __weak rpmh_invalidate(const void *dev) { return 0; }
EXPORT_SYMBOL(rpmh_invalidate);

int __weak rpmh_write_batch(const void *dev, int state,
			    const void *cmd, u32 *n)
{ return 0; }
EXPORT_SYMBOL(rpmh_write_batch);

void __weak rpmh_modem_sleepinfo_buffer_clear(void) {}
EXPORT_SYMBOL(rpmh_modem_sleepinfo_buffer_clear);

/* ── Command DB ──────────────────────────────────────────────────────── */
u32 __weak cmd_db_read_addr(const char *id) { return 0; }
EXPORT_SYMBOL(cmd_db_read_addr);

const void *__weak cmd_db_read_aux_data(const char *id, u8 *len)
{ if (len) *len = 0; return NULL; }
EXPORT_SYMBOL(cmd_db_read_aux_data);

u32 __weak cmd_db_read_slave_id(const char *id) { return 0; }
EXPORT_SYMBOL(cmd_db_read_slave_id);

int __weak cmd_db_ready(void) { return 0; }
EXPORT_SYMBOL(cmd_db_ready);

/* ── LLCC cache ──────────────────────────────────────────────────────── */
void *__weak llcc_slice_getd(u32 uid) { return ERR_PTR(-ENODEV); }
EXPORT_SYMBOL(llcc_slice_getd);

void __weak llcc_slice_putd(void *desc) {}
EXPORT_SYMBOL(llcc_slice_putd);

int __weak llcc_slice_activate(void *desc) { return 0; }
EXPORT_SYMBOL(llcc_slice_activate);

int __weak llcc_slice_deactivate(void *desc) { return 0; }
EXPORT_SYMBOL(llcc_slice_deactivate);

int __weak llcc_get_slice_id(void *desc) { return 0; }
EXPORT_SYMBOL(llcc_get_slice_id);

int __weak llcc_tcm_activate(void *desc) { return 0; }
EXPORT_SYMBOL(llcc_tcm_activate);

void __weak llcc_tcm_deactivate(void *desc) {}
EXPORT_SYMBOL(llcc_tcm_deactivate);

/* ── QMI framework ───────────────────────────────────────────────────── */
int __weak qmi_handle_init(void *qmi, size_t recv_buf_size, void *ops,
			   const void *handlers)
{ return -ENODEV; }
EXPORT_SYMBOL(qmi_handle_init);

void __weak qmi_handle_release(void *qmi) {}
EXPORT_SYMBOL(qmi_handle_release);

int __weak qmi_add_lookup(void *qmi, u16 service, u16 version, u16 instance)
{ return -ENODEV; }
EXPORT_SYMBOL(qmi_add_lookup);

int __weak qmi_add_server(void *qmi, u16 service, u16 version, u16 instance)
{ return -ENODEV; }
EXPORT_SYMBOL(qmi_add_server);

int __weak qmi_txn_init(void *qmi, void *txn, void *ei, void *c_struct)
{ return -ENODEV; }
EXPORT_SYMBOL(qmi_txn_init);

int __weak qmi_txn_wait(void *txn, unsigned long timeout_ms)
{ return -ETIMEDOUT; }
EXPORT_SYMBOL(qmi_txn_wait);

void __weak qmi_txn_cancel(void *txn) {}
EXPORT_SYMBOL(qmi_txn_cancel);

int __weak qmi_send_request(void *qmi, void *sq, void *txn, int msg_id,
			    size_t len, void *ei, const void *c_struct)
{ return -ENODEV; }
EXPORT_SYMBOL(qmi_send_request);

int __weak qmi_send_response(void *qmi, void *sq, void *txn, int msg_id,
			     size_t len, void *ei, const void *c_struct)
{ return -ENODEV; }
EXPORT_SYMBOL(qmi_send_response);

int __weak qmi_send_indication(void *qmi, void *sq, int msg_id, size_t len,
			       void *ei, const void *c_struct)
{ return -ENODEV; }
EXPORT_SYMBOL(qmi_send_indication);

/*
 * qmi_response_type_v01_ei is a global array (struct qmi_elem_info[]).
 * Provide a zero-filled buffer large enough for callers that read it.
 */
unsigned char qmi_response_type_v01_ei[256] __weak;
EXPORT_SYMBOL(qmi_response_type_v01_ei);

/* ── PMIC glink ──────────────────────────────────────────────────────── */
void *__weak pmic_glink_register_client(void *dev, void *ops)
{ return ERR_PTR(-ENODEV); }
EXPORT_SYMBOL(pmic_glink_register_client);

int __weak pmic_glink_unregister_client(void *client) { return -ENODEV; }
EXPORT_SYMBOL(pmic_glink_unregister_client);

int __weak pmic_glink_write(void *client, void *data, size_t len)
{ return -ENODEV; }
EXPORT_SYMBOL(pmic_glink_write);

/* ── Hypervisor / secure buffer ──────────────────────────────────────── */
int __weak hyp_assign_phys(phys_addr_t addr, u64 size,
			   u32 *source_vm_list, int source_nelems,
			   int *dest_vmids, int *dest_perms, int dest_nelems)
{ return -ENODEV; }
EXPORT_SYMBOL(hyp_assign_phys);

int __weak hyp_assign_table(void *sgt,
			    u32 *source_vm_list, int source_nelems,
			    int *dest_vmids, int *dest_perms, int dest_nelems)
{ return -ENODEV; }
EXPORT_SYMBOL(hyp_assign_table);

int __weak msm_secure_get_vmid_perms(u32 vmid) { return -ENODEV; }
EXPORT_SYMBOL(msm_secure_get_vmid_perms);

/* ── Haven hypervisor ────────────────────────────────────────────────── */
int __weak hh_vcpu_populate_affinity_info(void *resource, unsigned int type)
{ return -ENODEV; }
EXPORT_SYMBOL(hh_vcpu_populate_affinity_info);

int __weak hh_vpm_grp_populate_info(void *resource, unsigned int type)
{ return -ENODEV; }
EXPORT_SYMBOL(hh_vpm_grp_populate_info);

/* ── QPNP PBS ────────────────────────────────────────────────────────── */
int __weak qpnp_pbs_trigger_event(void *dev, u8 bitmap) { return 0; }
EXPORT_SYMBOL(qpnp_pbs_trigger_event);

int __weak qpnp_pbs_trigger_single_event(void *dev) { return 0; }
EXPORT_SYMBOL(qpnp_pbs_trigger_single_event);

/* ── Run Queue Stats (tick-sched.c) ─────────────────────────────────── */
unsigned char rq_info[512] __weak;
EXPORT_SYMBOL(rq_info);

struct workqueue_struct *rq_wq __weak;
EXPORT_SYMBOL(rq_wq);

/* ── HH suspend sysctl ───────────────────────────────────────────────── */
int sysctl_hh_suspend_timeout_ms __weak;
EXPORT_SYMBOL(sysctl_hh_suspend_timeout_ms);

/* ── MSM perf events ─────────────────────────────────────────────────── */
void __weak msm_perf_events_update(int type, int event, pid_t pid,
				   int cpu, int freq, bool is_idle) {}
EXPORT_SYMBOL(msm_perf_events_update);

/* ── rimps PLH ───────────────────────────────────────────────────────── */
int __weak rimps_plh_init(void *pdev) { return 0; }
EXPORT_SYMBOL(rimps_plh_init);

/* ── PIL restart tracepoint ──────────────────────────────────────────── */
struct tracepoint __tracepoint_pil_restart_level __weak = {
	.name = "pil_restart_level",
};
EXPORT_SYMBOL(__tracepoint_pil_restart_level);
