.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* Pin_PSoC4A_XRES */
.set Pin_PSoC4A_XRES__0__MASK, 0x10
.set Pin_PSoC4A_XRES__0__PC, CYREG_PRT2_PC4
.set Pin_PSoC4A_XRES__0__PORT, 2
.set Pin_PSoC4A_XRES__0__SHIFT, 4
.set Pin_PSoC4A_XRES__AG, CYREG_PRT2_AG
.set Pin_PSoC4A_XRES__AMUX, CYREG_PRT2_AMUX
.set Pin_PSoC4A_XRES__BIE, CYREG_PRT2_BIE
.set Pin_PSoC4A_XRES__BIT_MASK, CYREG_PRT2_BIT_MASK
.set Pin_PSoC4A_XRES__BYP, CYREG_PRT2_BYP
.set Pin_PSoC4A_XRES__CTL, CYREG_PRT2_CTL
.set Pin_PSoC4A_XRES__DM0, CYREG_PRT2_DM0
.set Pin_PSoC4A_XRES__DM1, CYREG_PRT2_DM1
.set Pin_PSoC4A_XRES__DM2, CYREG_PRT2_DM2
.set Pin_PSoC4A_XRES__DR, CYREG_PRT2_DR
.set Pin_PSoC4A_XRES__INP_DIS, CYREG_PRT2_INP_DIS
.set Pin_PSoC4A_XRES__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set Pin_PSoC4A_XRES__LCD_EN, CYREG_PRT2_LCD_EN
.set Pin_PSoC4A_XRES__MASK, 0x10
.set Pin_PSoC4A_XRES__PORT, 2
.set Pin_PSoC4A_XRES__PRT, CYREG_PRT2_PRT
.set Pin_PSoC4A_XRES__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set Pin_PSoC4A_XRES__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set Pin_PSoC4A_XRES__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set Pin_PSoC4A_XRES__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set Pin_PSoC4A_XRES__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set Pin_PSoC4A_XRES__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set Pin_PSoC4A_XRES__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set Pin_PSoC4A_XRES__PS, CYREG_PRT2_PS
.set Pin_PSoC4A_XRES__SHIFT, 4
.set Pin_PSoC4A_XRES__SLW, CYREG_PRT2_SLW

/* USBFS_bus_reset */
.set USBFS_bus_reset__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBFS_bus_reset__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBFS_bus_reset__INTC_MASK, 0x800000
.set USBFS_bus_reset__INTC_NUMBER, 23
.set USBFS_bus_reset__INTC_PRIOR_NUM, 7
.set USBFS_bus_reset__INTC_PRIOR_REG, CYREG_NVIC_PRI_23
.set USBFS_bus_reset__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBFS_bus_reset__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* Pin_Status_LED */
.set Pin_Status_LED__0__MASK, 0x02
.set Pin_Status_LED__0__PC, CYREG_PRT3_PC1
.set Pin_Status_LED__0__PORT, 3
.set Pin_Status_LED__0__SHIFT, 1
.set Pin_Status_LED__AG, CYREG_PRT3_AG
.set Pin_Status_LED__AMUX, CYREG_PRT3_AMUX
.set Pin_Status_LED__BIE, CYREG_PRT3_BIE
.set Pin_Status_LED__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Pin_Status_LED__BYP, CYREG_PRT3_BYP
.set Pin_Status_LED__CTL, CYREG_PRT3_CTL
.set Pin_Status_LED__DM0, CYREG_PRT3_DM0
.set Pin_Status_LED__DM1, CYREG_PRT3_DM1
.set Pin_Status_LED__DM2, CYREG_PRT3_DM2
.set Pin_Status_LED__DR, CYREG_PRT3_DR
.set Pin_Status_LED__INP_DIS, CYREG_PRT3_INP_DIS
.set Pin_Status_LED__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Pin_Status_LED__LCD_EN, CYREG_PRT3_LCD_EN
.set Pin_Status_LED__MASK, 0x02
.set Pin_Status_LED__PORT, 3
.set Pin_Status_LED__PRT, CYREG_PRT3_PRT
.set Pin_Status_LED__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Pin_Status_LED__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Pin_Status_LED__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Pin_Status_LED__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Pin_Status_LED__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Pin_Status_LED__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Pin_Status_LED__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Pin_Status_LED__PS, CYREG_PRT3_PS
.set Pin_Status_LED__SHIFT, 1
.set Pin_Status_LED__SLW, CYREG_PRT3_SLW

/* USBFS_arb_int */
.set USBFS_arb_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBFS_arb_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBFS_arb_int__INTC_MASK, 0x400000
.set USBFS_arb_int__INTC_NUMBER, 22
.set USBFS_arb_int__INTC_PRIOR_NUM, 7
.set USBFS_arb_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_22
.set USBFS_arb_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBFS_arb_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBFS_ord_int */
.set USBFS_ord_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBFS_ord_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBFS_ord_int__INTC_MASK, 0x2000000
.set USBFS_ord_int__INTC_NUMBER, 25
.set USBFS_ord_int__INTC_PRIOR_NUM, 7
.set USBFS_ord_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_25
.set USBFS_ord_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBFS_ord_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBFS_sof_int */
.set USBFS_sof_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBFS_sof_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBFS_sof_int__INTC_MASK, 0x200000
.set USBFS_sof_int__INTC_NUMBER, 21
.set USBFS_sof_int__INTC_PRIOR_NUM, 7
.set USBFS_sof_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_21
.set USBFS_sof_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBFS_sof_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBFS_dp_int */
.set USBFS_dp_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBFS_dp_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBFS_dp_int__INTC_MASK, 0x1000
.set USBFS_dp_int__INTC_NUMBER, 12
.set USBFS_dp_int__INTC_PRIOR_NUM, 7
.set USBFS_dp_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_12
.set USBFS_dp_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBFS_dp_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* Clock_LED_1 */
.set Clock_LED_1__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set Clock_LED_1__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set Clock_LED_1__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set Clock_LED_1__CFG2_SRC_SEL_MASK, 0x07
.set Clock_LED_1__INDEX, 0x00
.set Clock_LED_1__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock_LED_1__PM_ACT_MSK, 0x01
.set Clock_LED_1__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock_LED_1__PM_STBY_MSK, 0x01

/* PWM_PWMUDB */
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B1_UDB07_08_ACTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG, CYREG_B1_UDB07_08_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG, CYREG_B1_UDB07_08_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG, CYREG_B1_UDB07_08_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG, CYREG_B1_UDB07_08_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG, CYREG_B1_UDB07_08_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG, CYREG_B1_UDB07_08_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG, CYREG_B1_UDB07_08_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG, CYREG_B1_UDB07_08_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK, 0x80
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS, 7
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B1_UDB07_ACTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG, CYREG_B1_UDB07_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG, CYREG_B1_UDB07_ST_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG, CYREG_B1_UDB07_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG, CYREG_B1_UDB07_ST_CTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__MASK, 0x80
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG, CYREG_B1_UDB07_MSK
.set PWM_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG, CYREG_B1_UDB06_07_A0
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG, CYREG_B1_UDB06_07_A1
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG, CYREG_B1_UDB06_07_D0
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG, CYREG_B1_UDB06_07_D1
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB06_07_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG, CYREG_B1_UDB06_07_F0
.set PWM_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG, CYREG_B1_UDB06_07_F1
.set PWM_PWMUDB_sP16_pwmdp_u0__A0_A1_REG, CYREG_B1_UDB06_A0_A1
.set PWM_PWMUDB_sP16_pwmdp_u0__A0_REG, CYREG_B1_UDB06_A0
.set PWM_PWMUDB_sP16_pwmdp_u0__A1_REG, CYREG_B1_UDB06_A1
.set PWM_PWMUDB_sP16_pwmdp_u0__D0_D1_REG, CYREG_B1_UDB06_D0_D1
.set PWM_PWMUDB_sP16_pwmdp_u0__D0_REG, CYREG_B1_UDB06_D0
.set PWM_PWMUDB_sP16_pwmdp_u0__D1_REG, CYREG_B1_UDB06_D1
.set PWM_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG, CYREG_B1_UDB06_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u0__F0_F1_REG, CYREG_B1_UDB06_F0_F1
.set PWM_PWMUDB_sP16_pwmdp_u0__F0_REG, CYREG_B1_UDB06_F0
.set PWM_PWMUDB_sP16_pwmdp_u0__F1_REG, CYREG_B1_UDB06_F1
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG, CYREG_B1_UDB07_08_A0
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG, CYREG_B1_UDB07_08_A1
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG, CYREG_B1_UDB07_08_D0
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG, CYREG_B1_UDB07_08_D1
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB07_08_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG, CYREG_B1_UDB07_08_F0
.set PWM_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG, CYREG_B1_UDB07_08_F1
.set PWM_PWMUDB_sP16_pwmdp_u1__A0_A1_REG, CYREG_B1_UDB07_A0_A1
.set PWM_PWMUDB_sP16_pwmdp_u1__A0_REG, CYREG_B1_UDB07_A0
.set PWM_PWMUDB_sP16_pwmdp_u1__A1_REG, CYREG_B1_UDB07_A1
.set PWM_PWMUDB_sP16_pwmdp_u1__D0_D1_REG, CYREG_B1_UDB07_D0_D1
.set PWM_PWMUDB_sP16_pwmdp_u1__D0_REG, CYREG_B1_UDB07_D0
.set PWM_PWMUDB_sP16_pwmdp_u1__D1_REG, CYREG_B1_UDB07_D1
.set PWM_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG, CYREG_B1_UDB07_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u1__F0_F1_REG, CYREG_B1_UDB07_F0_F1
.set PWM_PWMUDB_sP16_pwmdp_u1__F0_REG, CYREG_B1_UDB07_F0
.set PWM_PWMUDB_sP16_pwmdp_u1__F1_REG, CYREG_B1_UDB07_F1
.set PWM_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set PWM_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__0__MASK, 0x01
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__0__POS, 0
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB07_08_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__16BIT_STATUS_REG, CYREG_B1_UDB07_08_ST
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__2__MASK, 0x04
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__2__POS, 2
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__3__MASK, 0x08
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__3__POS, 3
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__5__MASK, 0x20
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__5__POS, 5
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__MASK, 0x2D
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__MASK_REG, CYREG_B1_UDB07_MSK
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__PER_ST_AUX_CTL_REG, CYREG_B1_UDB07_MSK_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__STATUS_AUX_CTL_REG, CYREG_B1_UDB07_ACTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__STATUS_CNT_REG, CYREG_B1_UDB07_ST_CTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__STATUS_CONTROL_REG, CYREG_B1_UDB07_ST_CTL
.set PWM_PWMUDB_sSTSReg_rstSts_stsreg__STATUS_REG, CYREG_B1_UDB07_ST

/* USBFS_ep_0 */
.set USBFS_ep_0__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBFS_ep_0__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBFS_ep_0__INTC_MASK, 0x1000000
.set USBFS_ep_0__INTC_NUMBER, 24
.set USBFS_ep_0__INTC_PRIOR_NUM, 7
.set USBFS_ep_0__INTC_PRIOR_REG, CYREG_NVIC_PRI_24
.set USBFS_ep_0__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBFS_ep_0__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBFS_ep_1 */
.set USBFS_ep_1__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBFS_ep_1__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBFS_ep_1__INTC_MASK, 0x01
.set USBFS_ep_1__INTC_NUMBER, 0
.set USBFS_ep_1__INTC_PRIOR_NUM, 7
.set USBFS_ep_1__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set USBFS_ep_1__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBFS_ep_1__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBFS_ep_2 */
.set USBFS_ep_2__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USBFS_ep_2__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USBFS_ep_2__INTC_MASK, 0x02
.set USBFS_ep_2__INTC_NUMBER, 1
.set USBFS_ep_2__INTC_PRIOR_NUM, 7
.set USBFS_ep_2__INTC_PRIOR_REG, CYREG_NVIC_PRI_1
.set USBFS_ep_2__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USBFS_ep_2__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* USBFS_USB */
.set USBFS_USB__ARB_CFG, CYREG_USB_ARB_CFG
.set USBFS_USB__ARB_EP1_CFG, CYREG_USB_ARB_EP1_CFG
.set USBFS_USB__ARB_EP1_INT_EN, CYREG_USB_ARB_EP1_INT_EN
.set USBFS_USB__ARB_EP1_SR, CYREG_USB_ARB_EP1_SR
.set USBFS_USB__ARB_EP2_CFG, CYREG_USB_ARB_EP2_CFG
.set USBFS_USB__ARB_EP2_INT_EN, CYREG_USB_ARB_EP2_INT_EN
.set USBFS_USB__ARB_EP2_SR, CYREG_USB_ARB_EP2_SR
.set USBFS_USB__ARB_EP3_CFG, CYREG_USB_ARB_EP3_CFG
.set USBFS_USB__ARB_EP3_INT_EN, CYREG_USB_ARB_EP3_INT_EN
.set USBFS_USB__ARB_EP3_SR, CYREG_USB_ARB_EP3_SR
.set USBFS_USB__ARB_EP4_CFG, CYREG_USB_ARB_EP4_CFG
.set USBFS_USB__ARB_EP4_INT_EN, CYREG_USB_ARB_EP4_INT_EN
.set USBFS_USB__ARB_EP4_SR, CYREG_USB_ARB_EP4_SR
.set USBFS_USB__ARB_EP5_CFG, CYREG_USB_ARB_EP5_CFG
.set USBFS_USB__ARB_EP5_INT_EN, CYREG_USB_ARB_EP5_INT_EN
.set USBFS_USB__ARB_EP5_SR, CYREG_USB_ARB_EP5_SR
.set USBFS_USB__ARB_EP6_CFG, CYREG_USB_ARB_EP6_CFG
.set USBFS_USB__ARB_EP6_INT_EN, CYREG_USB_ARB_EP6_INT_EN
.set USBFS_USB__ARB_EP6_SR, CYREG_USB_ARB_EP6_SR
.set USBFS_USB__ARB_EP7_CFG, CYREG_USB_ARB_EP7_CFG
.set USBFS_USB__ARB_EP7_INT_EN, CYREG_USB_ARB_EP7_INT_EN
.set USBFS_USB__ARB_EP7_SR, CYREG_USB_ARB_EP7_SR
.set USBFS_USB__ARB_EP8_CFG, CYREG_USB_ARB_EP8_CFG
.set USBFS_USB__ARB_EP8_INT_EN, CYREG_USB_ARB_EP8_INT_EN
.set USBFS_USB__ARB_EP8_SR, CYREG_USB_ARB_EP8_SR
.set USBFS_USB__ARB_INT_EN, CYREG_USB_ARB_INT_EN
.set USBFS_USB__ARB_INT_SR, CYREG_USB_ARB_INT_SR
.set USBFS_USB__ARB_RW1_DR, CYREG_USB_ARB_RW1_DR
.set USBFS_USB__ARB_RW1_RA, CYREG_USB_ARB_RW1_RA
.set USBFS_USB__ARB_RW1_RA_MSB, CYREG_USB_ARB_RW1_RA_MSB
.set USBFS_USB__ARB_RW1_WA, CYREG_USB_ARB_RW1_WA
.set USBFS_USB__ARB_RW1_WA_MSB, CYREG_USB_ARB_RW1_WA_MSB
.set USBFS_USB__ARB_RW2_DR, CYREG_USB_ARB_RW2_DR
.set USBFS_USB__ARB_RW2_RA, CYREG_USB_ARB_RW2_RA
.set USBFS_USB__ARB_RW2_RA_MSB, CYREG_USB_ARB_RW2_RA_MSB
.set USBFS_USB__ARB_RW2_WA, CYREG_USB_ARB_RW2_WA
.set USBFS_USB__ARB_RW2_WA_MSB, CYREG_USB_ARB_RW2_WA_MSB
.set USBFS_USB__ARB_RW3_DR, CYREG_USB_ARB_RW3_DR
.set USBFS_USB__ARB_RW3_RA, CYREG_USB_ARB_RW3_RA
.set USBFS_USB__ARB_RW3_RA_MSB, CYREG_USB_ARB_RW3_RA_MSB
.set USBFS_USB__ARB_RW3_WA, CYREG_USB_ARB_RW3_WA
.set USBFS_USB__ARB_RW3_WA_MSB, CYREG_USB_ARB_RW3_WA_MSB
.set USBFS_USB__ARB_RW4_DR, CYREG_USB_ARB_RW4_DR
.set USBFS_USB__ARB_RW4_RA, CYREG_USB_ARB_RW4_RA
.set USBFS_USB__ARB_RW4_RA_MSB, CYREG_USB_ARB_RW4_RA_MSB
.set USBFS_USB__ARB_RW4_WA, CYREG_USB_ARB_RW4_WA
.set USBFS_USB__ARB_RW4_WA_MSB, CYREG_USB_ARB_RW4_WA_MSB
.set USBFS_USB__ARB_RW5_DR, CYREG_USB_ARB_RW5_DR
.set USBFS_USB__ARB_RW5_RA, CYREG_USB_ARB_RW5_RA
.set USBFS_USB__ARB_RW5_RA_MSB, CYREG_USB_ARB_RW5_RA_MSB
.set USBFS_USB__ARB_RW5_WA, CYREG_USB_ARB_RW5_WA
.set USBFS_USB__ARB_RW5_WA_MSB, CYREG_USB_ARB_RW5_WA_MSB
.set USBFS_USB__ARB_RW6_DR, CYREG_USB_ARB_RW6_DR
.set USBFS_USB__ARB_RW6_RA, CYREG_USB_ARB_RW6_RA
.set USBFS_USB__ARB_RW6_RA_MSB, CYREG_USB_ARB_RW6_RA_MSB
.set USBFS_USB__ARB_RW6_WA, CYREG_USB_ARB_RW6_WA
.set USBFS_USB__ARB_RW6_WA_MSB, CYREG_USB_ARB_RW6_WA_MSB
.set USBFS_USB__ARB_RW7_DR, CYREG_USB_ARB_RW7_DR
.set USBFS_USB__ARB_RW7_RA, CYREG_USB_ARB_RW7_RA
.set USBFS_USB__ARB_RW7_RA_MSB, CYREG_USB_ARB_RW7_RA_MSB
.set USBFS_USB__ARB_RW7_WA, CYREG_USB_ARB_RW7_WA
.set USBFS_USB__ARB_RW7_WA_MSB, CYREG_USB_ARB_RW7_WA_MSB
.set USBFS_USB__ARB_RW8_DR, CYREG_USB_ARB_RW8_DR
.set USBFS_USB__ARB_RW8_RA, CYREG_USB_ARB_RW8_RA
.set USBFS_USB__ARB_RW8_RA_MSB, CYREG_USB_ARB_RW8_RA_MSB
.set USBFS_USB__ARB_RW8_WA, CYREG_USB_ARB_RW8_WA
.set USBFS_USB__ARB_RW8_WA_MSB, CYREG_USB_ARB_RW8_WA_MSB
.set USBFS_USB__BUF_SIZE, CYREG_USB_BUF_SIZE
.set USBFS_USB__BUS_RST_CNT, CYREG_USB_BUS_RST_CNT
.set USBFS_USB__CR0, CYREG_USB_CR0
.set USBFS_USB__CR1, CYREG_USB_CR1
.set USBFS_USB__CWA, CYREG_USB_CWA
.set USBFS_USB__CWA_MSB, CYREG_USB_CWA_MSB
.set USBFS_USB__DMA_THRES, CYREG_USB_DMA_THRES
.set USBFS_USB__DMA_THRES_MSB, CYREG_USB_DMA_THRES_MSB
.set USBFS_USB__DYN_RECONFIG, CYREG_USB_DYN_RECONFIG
.set USBFS_USB__EP0_CNT, CYREG_USB_EP0_CNT
.set USBFS_USB__EP0_CR, CYREG_USB_EP0_CR
.set USBFS_USB__EP0_DR0, CYREG_USB_EP0_DR0
.set USBFS_USB__EP0_DR1, CYREG_USB_EP0_DR1
.set USBFS_USB__EP0_DR2, CYREG_USB_EP0_DR2
.set USBFS_USB__EP0_DR3, CYREG_USB_EP0_DR3
.set USBFS_USB__EP0_DR4, CYREG_USB_EP0_DR4
.set USBFS_USB__EP0_DR5, CYREG_USB_EP0_DR5
.set USBFS_USB__EP0_DR6, CYREG_USB_EP0_DR6
.set USBFS_USB__EP0_DR7, CYREG_USB_EP0_DR7
.set USBFS_USB__EP_ACTIVE, CYREG_USB_EP_ACTIVE
.set USBFS_USB__EP_TYPE, CYREG_USB_EP_TYPE
.set USBFS_USB__MEM_DATA, CYREG_USB_MEM_DATA_MBASE
.set USBFS_USB__PM_ACT_CFG, CYREG_PM_ACT_CFG5
.set USBFS_USB__PM_ACT_MSK, 0x01
.set USBFS_USB__PM_STBY_CFG, CYREG_PM_STBY_CFG5
.set USBFS_USB__PM_STBY_MSK, 0x01
.set USBFS_USB__SIE_EP1_CNT0, CYREG_USB_SIE_EP1_CNT0
.set USBFS_USB__SIE_EP1_CNT1, CYREG_USB_SIE_EP1_CNT1
.set USBFS_USB__SIE_EP1_CR0, CYREG_USB_SIE_EP1_CR0
.set USBFS_USB__SIE_EP2_CNT0, CYREG_USB_SIE_EP2_CNT0
.set USBFS_USB__SIE_EP2_CNT1, CYREG_USB_SIE_EP2_CNT1
.set USBFS_USB__SIE_EP2_CR0, CYREG_USB_SIE_EP2_CR0
.set USBFS_USB__SIE_EP3_CNT0, CYREG_USB_SIE_EP3_CNT0
.set USBFS_USB__SIE_EP3_CNT1, CYREG_USB_SIE_EP3_CNT1
.set USBFS_USB__SIE_EP3_CR0, CYREG_USB_SIE_EP3_CR0
.set USBFS_USB__SIE_EP4_CNT0, CYREG_USB_SIE_EP4_CNT0
.set USBFS_USB__SIE_EP4_CNT1, CYREG_USB_SIE_EP4_CNT1
.set USBFS_USB__SIE_EP4_CR0, CYREG_USB_SIE_EP4_CR0
.set USBFS_USB__SIE_EP5_CNT0, CYREG_USB_SIE_EP5_CNT0
.set USBFS_USB__SIE_EP5_CNT1, CYREG_USB_SIE_EP5_CNT1
.set USBFS_USB__SIE_EP5_CR0, CYREG_USB_SIE_EP5_CR0
.set USBFS_USB__SIE_EP6_CNT0, CYREG_USB_SIE_EP6_CNT0
.set USBFS_USB__SIE_EP6_CNT1, CYREG_USB_SIE_EP6_CNT1
.set USBFS_USB__SIE_EP6_CR0, CYREG_USB_SIE_EP6_CR0
.set USBFS_USB__SIE_EP7_CNT0, CYREG_USB_SIE_EP7_CNT0
.set USBFS_USB__SIE_EP7_CNT1, CYREG_USB_SIE_EP7_CNT1
.set USBFS_USB__SIE_EP7_CR0, CYREG_USB_SIE_EP7_CR0
.set USBFS_USB__SIE_EP8_CNT0, CYREG_USB_SIE_EP8_CNT0
.set USBFS_USB__SIE_EP8_CNT1, CYREG_USB_SIE_EP8_CNT1
.set USBFS_USB__SIE_EP8_CR0, CYREG_USB_SIE_EP8_CR0
.set USBFS_USB__SIE_EP_INT_EN, CYREG_USB_SIE_EP_INT_EN
.set USBFS_USB__SIE_EP_INT_SR, CYREG_USB_SIE_EP_INT_SR
.set USBFS_USB__SOF0, CYREG_USB_SOF0
.set USBFS_USB__SOF1, CYREG_USB_SOF1
.set USBFS_USB__USBIO_CR0, CYREG_USB_USBIO_CR0
.set USBFS_USB__USBIO_CR1, CYREG_USB_USBIO_CR1
.set USBFS_USB__USB_CLK_EN, CYREG_USB_USB_CLK_EN

/* USBFS_Dm */
.set USBFS_Dm__0__MASK, 0x80
.set USBFS_Dm__0__PC, CYREG_IO_PC_PRT15_7_6_PC1
.set USBFS_Dm__0__PORT, 15
.set USBFS_Dm__0__SHIFT, 7
.set USBFS_Dm__AG, CYREG_PRT15_AG
.set USBFS_Dm__AMUX, CYREG_PRT15_AMUX
.set USBFS_Dm__BIE, CYREG_PRT15_BIE
.set USBFS_Dm__BIT_MASK, CYREG_PRT15_BIT_MASK
.set USBFS_Dm__BYP, CYREG_PRT15_BYP
.set USBFS_Dm__CTL, CYREG_PRT15_CTL
.set USBFS_Dm__DM0, CYREG_PRT15_DM0
.set USBFS_Dm__DM1, CYREG_PRT15_DM1
.set USBFS_Dm__DM2, CYREG_PRT15_DM2
.set USBFS_Dm__DR, CYREG_PRT15_DR
.set USBFS_Dm__INP_DIS, CYREG_PRT15_INP_DIS
.set USBFS_Dm__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set USBFS_Dm__LCD_EN, CYREG_PRT15_LCD_EN
.set USBFS_Dm__MASK, 0x80
.set USBFS_Dm__PORT, 15
.set USBFS_Dm__PRT, CYREG_PRT15_PRT
.set USBFS_Dm__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set USBFS_Dm__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set USBFS_Dm__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set USBFS_Dm__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set USBFS_Dm__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set USBFS_Dm__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set USBFS_Dm__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set USBFS_Dm__PS, CYREG_PRT15_PS
.set USBFS_Dm__SHIFT, 7
.set USBFS_Dm__SLW, CYREG_PRT15_SLW

/* USBFS_Dp */
.set USBFS_Dp__0__MASK, 0x40
.set USBFS_Dp__0__PC, CYREG_IO_PC_PRT15_7_6_PC0
.set USBFS_Dp__0__PORT, 15
.set USBFS_Dp__0__SHIFT, 6
.set USBFS_Dp__AG, CYREG_PRT15_AG
.set USBFS_Dp__AMUX, CYREG_PRT15_AMUX
.set USBFS_Dp__BIE, CYREG_PRT15_BIE
.set USBFS_Dp__BIT_MASK, CYREG_PRT15_BIT_MASK
.set USBFS_Dp__BYP, CYREG_PRT15_BYP
.set USBFS_Dp__CTL, CYREG_PRT15_CTL
.set USBFS_Dp__DM0, CYREG_PRT15_DM0
.set USBFS_Dp__DM1, CYREG_PRT15_DM1
.set USBFS_Dp__DM2, CYREG_PRT15_DM2
.set USBFS_Dp__DR, CYREG_PRT15_DR
.set USBFS_Dp__INP_DIS, CYREG_PRT15_INP_DIS
.set USBFS_Dp__INTSTAT, CYREG_PICU15_INTSTAT
.set USBFS_Dp__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set USBFS_Dp__LCD_EN, CYREG_PRT15_LCD_EN
.set USBFS_Dp__MASK, 0x40
.set USBFS_Dp__PORT, 15
.set USBFS_Dp__PRT, CYREG_PRT15_PRT
.set USBFS_Dp__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set USBFS_Dp__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set USBFS_Dp__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set USBFS_Dp__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set USBFS_Dp__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set USBFS_Dp__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set USBFS_Dp__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set USBFS_Dp__PS, CYREG_PRT15_PS
.set USBFS_Dp__SHIFT, 6
.set USBFS_Dp__SLW, CYREG_PRT15_SLW
.set USBFS_Dp__SNAP, CYREG_PICU_15_SNAP_15

/* Miscellaneous */
/* -- WARNING: define names containing LEOPARD or PANTHER are deprecated and will be removed in a future release */
.set CYDEV_BOOTLOADER_IO_COMP_CUSTOM_IO, 0
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_MEMBER_5B, 4
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_DIE_PSOC5LP, 4
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_DIE_PSOC5LP
.set CYDEV_BOOTLOADER_IO_COMP_USBFS, 1
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_BOOTLOADER_APPLICATIONS, 1
.set CYDEV_BOOTLOADER_CHECKSUM_BASIC, 0
.set CYDEV_BOOTLOADER_CHECKSUM_CRC, 1
.set CYDEV_BOOTLOADER_IO_COMP, CYDEV_BOOTLOADER_IO_COMP_USBFS
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 3
.set CYDEV_CHIP_DIE_PSOC4A, 2
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E105069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 2
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REV_PSOC5LP_PRODUCTION
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 0
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowWithInfo
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_Disable
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_REQXRES, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x1000
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000000
.set CYDEV_PROJ_TYPE, 1
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x1000
.set CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP, 1
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0, 5
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1, 5
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2, 5
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3, 5
.set CYDEV_VIO3_MV, 5000
.set CyBtldr_Custom_Interface, CYDEV_BOOTLOADER_IO_COMP_CUSTOM_IO
.set CyBtldr_USBFS, CYDEV_BOOTLOADER_IO_COMP_USBFS
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 1
.endif