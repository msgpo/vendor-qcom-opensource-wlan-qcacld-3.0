/*
 * Copyright (c) 2013-2017 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

/************************************************************************
   smeTrace.c

   \brief implementation for trace related APIs

   \author Kiran Kumar Reddy CH L V

   ========================================================================*/
#include "ani_global.h"          /* for tpAniSirGlobal */
#include "sms_debug.h"
#include "mac_trace.h"
#include "sme_trace.h"
#include "sme_internal.h"
#ifndef SME_TRACE_RECORD
void sme_trace_init(tpAniSirGlobal pMac)
{
	return;
}
#endif
#ifdef SME_TRACE_RECORD

static uint8_t *sme_trace_get_rx_msg_string(uint32_t code)
{
	switch (code) {
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_REQ);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_GET_RESULTS);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_CONNECT);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SET_11DINFO);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_GET_SOFTAP_DOMAIN);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SET_REGINFO);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_MSG_UPDATE_CHANNEL_CONFIG);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_UPDATE_CONFIG);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_HDDREADYIND);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_MSG_SCAN_FLUSH_RESULTS);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_MSG_SCAN_FLUSH_P2PRESULTS);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_MSG_SCAN_RESULT_GETFIRST);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_MSG_SCAN_RESULT_GETNEXT);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_SCAN_RESULT_PURGE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_REASSOC);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_DISCONNECT);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_ROAM_GET_CONNECTPROFILE);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_ROAM_FREE_CONNECTPROFILE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_SET_PMKIDCACHE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_DEL_PMKIDCACHE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ROAM_GET_PMKIDCACHE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_CONFIGPARAM);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_MODPROFFIELDS);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_CONFIG_PWRSAVE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_CONFIG_PWRSAVE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ENABLE_PWRSAVE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DISABLE_PWRSAVE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SIGNAL_POWER_EVENT);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_START_AUTO_BMPSTIMER);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_STOP_AUTO_BMPSTIMER);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_IS_PWRSAVE_ENABLED);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REQUEST_FULLPOWER);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REQUEST_BMPS);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_DHCP_FLAG);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REQUEST_STANDBY);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_WOWL_ADDBCAST_PATTERN);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_WOWL_DELBCAST_PATTERN);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ENTER_WOWL);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_EXIT_WOWL);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_KEY);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REMOVE_KEY);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_STATS);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_RSSI);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_CNTRYCODE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_CNTRYCODE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CHANGE_CNTRYCODE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_CFGPRIVACY);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_NEIGHBOR_REPORTREQ);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DBG_READREG);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DBG_WRITEREG);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DBG_READMEM);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DBG_WRITEMEM);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_OPEN_SESSION);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CLOSE_SESSION);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_HOSTOFFLOAD);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_GTKOFFLOAD);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_GTKOFFLOAD);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ABORT_MACSCAN);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REGISTER_MGMTFR);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DEREGISTER_MGMTFR);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_REMAIN_ONCHAN);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SEND_ACTION);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CANCEL_REMAIN_ONCHAN);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_RXPFIL);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_SUSPENDIND);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_RESUMEREQ);
#ifdef WLAN_FEATURE_EXTWOW_SUPPORT
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_EXTWOW);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_APP_TYPE1);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CONFIG_APP_TYPE2);
#endif
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_MAXTXPOW);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_TXPOW);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_TMLEVEL);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CAPS_EXCH);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_DISABLE_CAP);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_DEFCCNV);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_CURCC);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_RESET_PW5G);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_RP5G);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_ROAMIBAND);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_GET_ROAMIBAND);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_RSSIDIFF);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_IMMRSSIDIFF);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_FTENABLED);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_WESMODE);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_SET_SCANCTRL);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_UPDATE_P2P_IE);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_UPDATE_ROAM_SCAN_N_PROBES);
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_UPDATE_ROAM_SCAN_HOME_AWAY_TIME);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_STORE_JOIN_REQ);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_CLEAR_JOIN_REQ);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_ISSUE_JOIN_REQ);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_MSG_DEAUTH_STA);
#ifdef FEATURE_WLAN_TDLS
		CASE_RETURN_STRING
			(TRACE_CODE_SME_RX_HDD_TDLS_LINK_ESTABLISH_PARAM);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_CHAN_SWITCH_REQ);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_SEND_MGMT_FRAME);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_CHANGE_PEER_STA);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_ADD_PEER_STA);
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_TDLS_DEL_PEER_STA);
#endif
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_PREF_NET_LIST);
#ifdef FEATURE_WLAN_LPHB
		CASE_RETURN_STRING(TRACE_CODE_SME_RX_HDD_LPHB_CONFIG_REQ);
#endif /* FEATURE_WLAN_LPHB */

	default:
		return "UNKNOWN";
		break;
	}
}

static uint8_t *sme_trace_get_command_string(uint32_t command)
{
	switch (command) {
		CASE_RETURN_STRING(eSmeNoCommand);
		CASE_RETURN_STRING(eSmeDropCommand);
		CASE_RETURN_STRING(eSmeCsrCommandMask);
		CASE_RETURN_STRING(eSmeCommandScan);
		CASE_RETURN_STRING(eSmeCommandRoam);
		CASE_RETURN_STRING(eSmeCommandWmStatusChange);
		CASE_RETURN_STRING(eSmeCommandSetKey);
		CASE_RETURN_STRING(eSmeCommandAddStaSession);
		CASE_RETURN_STRING(eSmeCommandDelStaSession);
#ifdef FEATURE_WLAN_TDLS
		CASE_RETURN_STRING(eSmeCommandTdlsSendMgmt);
		CASE_RETURN_STRING(eSmeCommandTdlsAddPeer);
		CASE_RETURN_STRING(eSmeCommandTdlsDelPeer);
		CASE_RETURN_STRING(eSmeCommandTdlsLinkEstablish);
#endif
		CASE_RETURN_STRING(eSmePmcCommandMask);
		CASE_RETURN_STRING(eSmeCommandEnterBmps);
		CASE_RETURN_STRING(eSmeCommandExitBmps);
		CASE_RETURN_STRING(eSmeCommandEnterUapsd);
		CASE_RETURN_STRING(eSmeCommandExitUapsd);
		CASE_RETURN_STRING(eSmeCommandExitWowl);
		CASE_RETURN_STRING(eSmeCommandEnterStandby);
		CASE_RETURN_STRING(eSmeQosCommandMask);
		CASE_RETURN_STRING(eSmeCommandAddTs);
		CASE_RETURN_STRING(eSmeCommandDelTs);
#ifdef FEATURE_OEM_DATA_SUPPORT
		CASE_RETURN_STRING(eSmeCommandOemDataReq);
#endif
		CASE_RETURN_STRING(eSmeCommandRemainOnChannel);
		CASE_RETURN_STRING(e_sme_command_set_hw_mode);
		CASE_RETURN_STRING(e_sme_command_nss_update);
		CASE_RETURN_STRING(e_sme_command_set_dual_mac_config);
		CASE_RETURN_STRING(e_sme_command_set_antenna_mode);
		CASE_RETURN_STRING(eSmeCommandNdpInitiatorRequest);
		CASE_RETURN_STRING(eSmeCommandNdpResponderRequest);
		CASE_RETURN_STRING(eSmeCommandNdpDataEndInitiatorRequest);
	default:
		return "UNKNOWN";
		break;
	}
}

static void sme_trace_dump(tpAniSirGlobal mac_ctx, tp_qdf_trace_record record,
			   uint16_t rec_index)
{
	switch (record->code) {
	case TRACE_CODE_SME_COMMAND:
		sms_log(mac_ctx, LOGD, "%04d %012llu %s S%d %-14s %-30s(0x%x)",
			rec_index, record->qtime, record->time, record->session,
			"SME COMMAND:",
			sme_trace_get_command_string(record->data),
			record->data);
		break;
	case TRACE_CODE_SME_TX_WMA_MSG:
		sms_log(mac_ctx, LOGD, "%04d %012llu %s S%d %-14s %-30s(0x%x)",
			rec_index, record->qtime, record->time, record->session,
			"TX WMA Msg:",
			mac_trace_get_wma_msg_string((uint16_t)record->data),
			record->data);
		break;
	case TRACE_CODE_SME_RX_WMA_MSG:
		sms_log(mac_ctx, LOGD, "%04d %012llu %s S%d %-14s %-30s(0x%x)",
			rec_index, record->qtime, record->time, record->session,
			"RX WMA Msg:",
			mac_trace_get_sme_msg_string((uint16_t)record->data),
			record->data);
		break;
	default:
		sms_log(mac_ctx, LOGD, "%04d %012llu %s S%d %-14s %-30s(0x%x)",
			rec_index, record->qtime, record->time, record->session,
			"RX HDD MSG:",
			sme_trace_get_rx_msg_string(record->code),
			record->data);
		break;
	}
}

void sme_trace_init(tpAniSirGlobal pMac)
{
	qdf_trace_register(QDF_MODULE_ID_SME, (tp_qdf_trace_cb) &sme_trace_dump);
}
#endif
