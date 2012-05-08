// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder
#ifndef _RRCONFIGS_CONST_
#define _RRCONFIGS_CONST_

/**
 * rAthena configuration file (http://rathena.org)
 * For detailed guidance on these check http://rathena.org/wiki/SRC/map/config/
 **/

/**
 * @INFO: This file holds constants that aims at making code smoother and more efficient
 */

/**
 * "Constants"
 **/
#ifdef RENEWAL_CAST

	#ifndef RENEWAL
		#error RENEWAL_CAST requires RENEWAL enabled
	#endif

	#define CONST_CASTRATE_SCALE RENEWAL_CAST_VMIN
	/**
	 * Cast Rate Formula: (DEX x 2)+INT
	 **/
	#define CONST_CASTRATE_CALC ((status_get_dex(bl)*2)+status_get_int(bl))
#else
	#define CONST_CASTRATE_SCALE battle_config.castrate_dex_scale
	/**
	 * Cast Rate Formula: (DEX)
	 **/
	#define CONST_CASTRATE_CALC (status_get_dex(bl))
#endif

/**
 * "Sane Checks" to save you from compiling with cool bugs 
 **/
#if SECURE_NPCTIMEOUT_INTERVAL <= 0
	#error SECURE_NPCTIMEOUT_INTERVAL should be at least 1 (1s)
#endif
#if SECURE_NPCTIMEOUT < 0
	#error SECURE_NPCTIMEOUT cannot be lower than 0
#endif

/**
 * Path within the /db folder to (non-)renewal specific db files
 **/
#ifdef RENEWAL
	#define DBPATH "re/"
#elif OLDTIMES
	#define DBPATH "ot/"
#else
	#define DBPATH "pre-re/"
#endif


#ifdef __64BIT__
	#define __64BPRTSIZE(y) (intptr)y
#else
	#define __64BPRTSIZE(y) y
#endif

/* ATCMD_FUNC(mobinfo) HIT and FLEE calculations */
#ifdef RENEWAL
	#define MOB_FLEE(mob) ( mob->lv + mob->status.dex + mob->status.luk/3 + 175 )
	#define MOB_HIT(mob)  ( mob->lv + mob->status.agi + mob->status.luk/5 + 100 )
#else
	#define MOB_FLEE(mob) ( mob->lv + mob->status.dex )
	#define MOB_HIT(mob)  ( mob->lv + mob->status.agi )
#endif

/**
 * End of File
 **/
#endif