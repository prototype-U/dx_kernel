/*
 * Copyright (c) 2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __ARCH_ARM_MACH_MSM_SMEM_IFACE_H
#define __ARCH_ARM_MACH_MSM_SMEM_IFACE_H

#include <mach/msm_smsm.h>

#define MAX_KEY_EVENTS 10
#define MAX_SEC_KEY_PAYLOAD 32

struct boot_shared_ssd_status_info {
	uint32_t update_status;  
	uint32_t bl_error_code;  
};

struct boot_symmetric_key_info {
	uint32_t key_len; 
	uint32_t iv_len;  
	uint8_t  key[MAX_SEC_KEY_PAYLOAD]; 
	uint8_t  iv[MAX_SEC_KEY_PAYLOAD]; 
};

struct cpr_info_type {
	uint8_t ring_osc;   
	uint8_t turbo_quot; 
	uint8_t pvs_fuse;   
	uint8_t floor_fuse; 
	bool    disable_cpr;
};

struct boot_info_for_apps {
	uint32_t apps_image_start_addr; 
	uint32_t boot_flags; 
	struct boot_shared_ssd_status_info ssd_status_info; 
	struct boot_symmetric_key_info key_info;
	uint16_t boot_keys_pressed[MAX_KEY_EVENTS]; 
	uint32_t timetick; 
	struct cpr_info_type cpr_info;
	uint8_t PAD[23];
};

void msm_smem_get_cpr_info(struct cpr_info_type *cpr_info);

#endif 
