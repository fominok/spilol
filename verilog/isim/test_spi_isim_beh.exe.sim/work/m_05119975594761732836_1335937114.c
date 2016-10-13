/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/yolo/fpga/spilol/spi.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 4294967295U};
static int ng3[] = {1, 0};
static int ng4[] = {8, 0};



static void Cont_22_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 4232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(22, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    t2 = (t0 + 5160);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 0);
    t16 = (t0 + 5048);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Always_24_1(char *t0)
{
    char t14[8];
    char t33[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;

LAB0:    t1 = (t0 + 4480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(24, ng0);
    t2 = (t0 + 5064);
    *((int *)t2) = 1;
    t3 = (t0 + 4512);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(24, ng0);

LAB5:    xsi_set_current_line(25, ng0);
    t4 = (t0 + 1960U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB10:    t5 = (t0 + 472);
    t11 = *((char **)t5);
    t13 = xsi_vlog_unsigned_case_compare(t4, 8, t11, 32);
    if (t13 == 1)
        goto LAB11;

LAB12:    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t13 = xsi_vlog_unsigned_case_compare(t4, 8, t3, 32);
    if (t13 == 1)
        goto LAB13;

LAB14:
LAB15:    goto LAB2;

LAB6:    xsi_set_current_line(25, ng0);

LAB9:    xsi_set_current_line(26, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(29, ng0);

LAB16:    xsi_set_current_line(30, ng0);
    t5 = ((char*)((ng2)));
    t12 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t12, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(31, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(32, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB17;

LAB18:
LAB19:    goto LAB15;

LAB13:    xsi_set_current_line(39, ng0);

LAB21:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 3160);
    t5 = (t2 + 56U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng1)));
    memset(t14, 0, 8);
    t15 = (t11 + 4);
    t16 = (t12 + 4);
    t6 = *((unsigned int *)t11);
    t7 = *((unsigned int *)t12);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t15);
    t10 = *((unsigned int *)t16);
    t17 = (t9 ^ t10);
    t18 = (t8 | t17);
    t19 = *((unsigned int *)t15);
    t20 = *((unsigned int *)t16);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB25;

LAB22:    if (t21 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t14) = 1;

LAB25:    t25 = (t14 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t14);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(44, ng0);

LAB30:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = (t0 + 3320);
    t12 = (t11 + 72U);
    t15 = *((char **)t12);
    t16 = (t0 + 3160);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t31 = ((char*)((ng3)));
    memset(t33, 0, 8);
    xsi_vlog_unsigned_minus(t33, 32, t25, 8, t31, 32);
    xsi_vlog_generic_get_index_select_value(t14, 1, t5, t15, 2, t33, 32, 2);
    t32 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t32, t14, 0, 0, 1, 0LL);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 3160);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = ((char*)((ng3)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_minus(t14, 32, t5, 8, t11, 32);
    t12 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 8, 0LL);

LAB28:    goto LAB15;

LAB17:    xsi_set_current_line(32, ng0);

LAB20:    xsi_set_current_line(33, ng0);
    t5 = ((char*)((ng4)));
    t11 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t11, t5, 0, 0, 8, 0LL);
    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(35, ng0);
    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t2 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1640U);
    t3 = *((char **)t2);
    t2 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    goto LAB19;

LAB24:    t24 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(40, ng0);

LAB29:    xsi_set_current_line(41, ng0);
    t31 = ((char*)((ng2)));
    t32 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t32, t31, 0, 0, 1, 0LL);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(43, ng0);
    t2 = (t0 + 472);
    t3 = *((char **)t2);
    t2 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    goto LAB28;

}

static void Always_52_2(char *t0)
{
    char t9[8];
    char t32[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    unsigned int t40;
    int t41;

LAB0:    t1 = (t0 + 4728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 5080);
    *((int *)t2) = 1;
    t3 = (t0 + 4760);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(52, ng0);

LAB5:    xsi_set_current_line(53, ng0);
    t4 = (t0 + 3000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 608);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t7 = (t6 + 4);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t8);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB9;

LAB6:    if (t20 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t9) = 1;

LAB9:    t24 = (t9 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t9);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB8:    t23 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(53, ng0);

LAB13:    xsi_set_current_line(54, ng0);
    t30 = (t0 + 1480U);
    t31 = *((char **)t30);
    t30 = (t0 + 2840);
    t33 = (t0 + 2840);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 3160);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    xsi_vlog_generic_convert_bit_index(t32, t35, 2, t38, 8, 2);
    t39 = (t32 + 4);
    t40 = *((unsigned int *)t39);
    t41 = (!(t40));
    if (t41 == 1)
        goto LAB14;

LAB15:    goto LAB12;

LAB14:    xsi_vlogvar_wait_assign_value(t30, t31, 0, *((unsigned int *)t32), 1, 0LL);
    goto LAB15;

}


extern void work_m_05119975594761732836_1335937114_init()
{
	static char *pe[] = {(void *)Cont_22_0,(void *)Always_24_1,(void *)Always_52_2};
	xsi_register_didat("work_m_05119975594761732836_1335937114", "isim/test_spi_isim_beh.exe.sim/work/m_05119975594761732836_1335937114.didat");
	xsi_register_executes(pe);
}
