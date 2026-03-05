// SPDX-License-Identifier: GPL-2.0-only
/*
 * Stub implementations for OPlus/MSM display notifier APIs.
 *
 * msm_drm_register_client / msm_drm_unregister_client are part of the
 * MSM DRM notifier subsystem used by many OPlus drivers to receive
 * display panel state change events.
 *
 * register_lcdinfo_notifier / unregister_lcdinfo_notifier are OPlus
 * proprietary extensions to the same notifier chain, added in their
 * display fork.
 *
 * When techpack/display is not present or does not export these symbols
 * (e.g. standalone kernel builds without the matching OPlus display tree),
 * these stubs provide no-op weak implementations so that the kernel links
 * successfully.  Any caller that relies on display events will simply not
 * receive them — acceptable for a base CI build.
 */

#include <linux/module.h>
#include <linux/notifier.h>
#include <linux/export.h>

int __attribute__((weak)) msm_drm_register_client(struct notifier_block *nb)
{
	return 0;
}
EXPORT_SYMBOL(msm_drm_register_client);

int __attribute__((weak)) msm_drm_unregister_client(struct notifier_block *nb)
{
	return 0;
}
EXPORT_SYMBOL(msm_drm_unregister_client);

int __attribute__((weak)) register_lcdinfo_notifier(struct notifier_block *nb)
{
	return 0;
}
EXPORT_SYMBOL(register_lcdinfo_notifier);

int __attribute__((weak)) unregister_lcdinfo_notifier(struct notifier_block *nb)
{
	return 0;
}
EXPORT_SYMBOL(unregister_lcdinfo_notifier);
