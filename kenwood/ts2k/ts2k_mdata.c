/*
 * ts2k_menu.h	(C) Copyright 2002 by Dale E. Edmons.  All rights reserved.
 */

/*
 * License:	GNU (same as what hamlib currently is using)
 */

/*
 * status:	uncompiled.  Haven't finished factory defaults.
 *		anything with m_tbd is: to be developed
 */

#include "ts2k/ts2k.h"
#include "ts2k/ts2k_menu.h"

char *ts2k_m_text[] = {
	"", "On", "Off", "TO", "CO", "High Boost", "Bass Boost", "F Pass",
	"Conv", "User", "Auto", "Normal", "Inverse", "Low", "Mid", "High",
	"Burst", "Cont", "Slow", "Fast", "Main", "Sub", "TNC Band",
	"Main & Sub", "Manual", "Morse", "Voice", "Negative", "Positive",
	"Locked", "Cross", "Client", "Commander", "Transporter",
	"font1", "font2", "To Be Developed", ""
};
const char m_num[8+2];		// storage for numeric constants
const char m_text[8+2];		// storage for text constants

const char key_none[] = "None";

/*#define *M_TBD[] = {
	"Voice1", "Voice2", "Voice3", "RX Moni", "DSP Moni",
	"Quick Memo MR", "Quick Memo M.IN", "Split", "TF-SET",
	"A/B", "VFO/M", "A=B", "Scan", "M>VFO", "M.IN", "CW TUNE",
	"CH1", "CH2", "CH3", "Fine", "CLR", "Call", "CTRL",
	"1MHz", "ANT1/2", "N.B.", "N.R.", "B.C.", "A.N.",
	""
}; */

/*
 * Defaults for menu_t.val were obtained via minicom
 * on my rig after doing a full reset to factory defaults.
 * (unfinished)
 */

ts2k_menu_t ts2k_menus[] = {
	{ "00", "Display Brightness", {M_OFF, M_NUM, M_NULL},
		"", { 0,0,0,0}, 3},
	{ "01", "Key Illumination", {M_OFF, M_ON, M_NULL},
		"", { 1,0,0,0}, 1},
	{ "02", "Tuning Control Change Per Revolution", {M_NUM, M_NULL},
		"", { 2,0,0,0}, 1},
	{ "03", "Tune using MULTI/CH Frequency Step", {M_OFF, M_ON, M_NULL},
		"", { 3,0,0,0}, 1},
	{ "04", "Round off VFO using MULTI/CH Control", {M_OFF, M_ON, M_NULL},
		"", { 4,0,0,0}, 1},
	{ "05", "9kHz step size for MULTI/CH in AM Broadcast Band", {M_OFF, M_ON, M_NULL},
		 "", { 5,0,0,0}, 0},
	{ "06A", "Mem: Memory-VFO Split", {M_OFF, M_ON, M_NULL}, "", {06,1,0,0}, 0},
	{ "06B", "Mem: Temporary Frequency change after Memory Recall", {M_OFF, M_ON, M_NULL},
		 "", { 6,2,0,0}, 0},
	{ "07", "Program scan partially slowed", {M_OFF, M_ON, M_NULL},
		 "", { 7,0,0,0}, 0},
	{ "08", "Program Slow-Scan Range", {M_NUM, M_NULL},
		 "", { 8,0,0,0}, 0},
	{ "09", "Program scan hold", {M_OFF, M_ON, M_NULL},
		 "", { 9,0,0,0}, 0},
	{ "10", "Scan Resume Method", {M_TO, M_CO, M_NULL},
		 "", {10,0,0,0}, 0},
	{ "11", "Visual Scan Range", {M_TBD, M_NULL},
		 "", {11,0,0,0}, 0},
	{ "12", "Beep Volume", {M_OFF, M_NUM, M_NULL},
		 "", {12,0,0,0}, 0},
	{ "13", "Sidetone Volume", {M_OFF, M_NUM, M_NULL},
		 "", {13,0,0,0}, 0},
	{ "14", "Message Playback Volume", {M_OFF, M_NUM, M_NULL},
		 "", {14,0,0,0}, 0},
	{ "15", "Voice Volume", {M_OFF, M_NUM, M_NULL},
		 "", {15,0,0,0}, 0},
	{ "16", "Output Configuration for sp2 or headphones", {M_TBD, M_NULL},
		 "", {16,0,0,0}, 0},
	{ "17", "Reversed output configuration for sp2 or headphones", {M_OFF, M_ON, M_NULL},
		 "", {17,0,0,0}, 0},
	{ "18", "RX-Dedicated antenna", {M_OFF, M_ON, M_NULL},
		 "", {18,0,0,0}, 0},
	{ "19A", "S-Meter: SQ", {M_OFF, M_ON, M_NULL},
		 "", {19,1,0,0}, 0},
	{ "19B", "S-Meter: Hang Time", {M_OFF, M_TBD, M_NULL},
		 "", {19,2,0,0}, 0},
	{ "20", "RX Equalizer", {M_OFF, M_H_BOOST, M_B_BOOST, M_CONVEN, M_USER, M_NULL},
		 "", {20,0,0,0}, 0},
	{ "21", "TX Equalizer", {M_OFF, M_H_BOOST, M_B_BOOST, M_CONVEN, M_USER, M_NULL},
		 "", {21,0,0,0}, 0},
	{ "22", "TX Filter Bandwidth for SSB or AM", {M_TBD, M_NULL},
		 "", {22,0,0,0}, 0},
	{ "23", "Fine Transmit power change step", {M_OFF, M_ON, M_NULL},
		 "", {23,0,0,0}, 0},
	{ "24", "Time-out Timer", {M_OFF, M_TBD, M_NULL},
		 "", {24,0,0,0}, 0},
	{ "25", "Transverter Frequency Display", {M_OFF, M_ON, M_NULL},
		 "", {25,0,0,0}, 0},
	{ "26", "TX Hold; Antenna tuner", {M_OFF, M_ON, M_NULL},
		 "", {26,0,0,0}, 0},
	{ "27", "Antenna tuner while receiving", {M_OFF, M_ON, M_NULL},
		 "", {27,0,0,0}, 0},
	{ "28A", "Linear Amp Control Relay: HF", {M_OFF, M_NUM, M_NULL},
		 "", {28,1,0,0}, 0},
	{ "28B", "Linear Amp Control Relay: 50MHz", {M_OFF, M_NUM, M_NULL},
		 "", {28,2,0,0}, 0},
	{ "28C", "Linear Amp Control Relay: 144MHz", {M_OFF, M_NUM, M_NULL},
		 "", {28,3,0,0}, 0},
	{ "28D", "Linear Amp Control Relay: 430MHz", {M_OFF, M_NUM, M_NULL},
		 "", {28,4,0,0}, 0},
	{ "28E", "Linear Amp Control Relay: 1.2GHz", {M_OFF, M_NUM, M_NULL},
		 "", {28,5,0,0}, 0},
	{ "29A", "CW Message: Playback Repeat", {M_OFF, M_ON, M_NULL},
		 "", {29,1,0,0}, 0},
	{ "29B", "CW Message: Playback Interval", {M_NUM, M_NULL},
		 "", {29,2,0,0}, 0},
	{ "30", "Keying Priority over playback", {M_OFF, M_ON, M_NULL},
		 "", {30,0,0,0}, 0},
	{ "31", "CW RX Pitch/TX sidetone frequency", {M_TBD, M_NULL},
		 "", {31,0,0,0}, 0},
	{ "32", "CW rise time", {M_TBD, M_NULL},
		 "", {32,0,0,0}, 0},
	{ "33", "CW weighting", {M_AUTO, M_TBD, M_NULL},
		 "", {33,0,0,0}, 0},
	{ "34", "Reversed CW weighting", {M_OFF, M_ON, M_NULL},
		 "", {34,0,0,0}, 0},
	{ "35", "Bug key function", {M_OFF, M_ON, M_NULL},
		 "", {35,0,0,0}, 0},
	{ "36", "Auto CW TX when keying in SSB", {M_OFF, M_ON, M_NULL},
		 "", {36,0,0,0}, 0},
	{ "37", "Frequency correction for SSB-to-CW change", {M_OFF, M_ON, M_NULL},
		 "", {37,0,0,0}, 0},
	{ "38", "FSK shift", {M_TBD, M_NULL},
		 "", {38,0,0,0}, 0},
	{ "39", "FSK key-down polarity", {M_NORM, M_INV, M_NULL},
		 "", {39,0,0,0}, 0},
	{ "40", "FSK tone frequency", {M_TBD, M_NULL},
		 "", {40,0,0,0}, 0},
	{ "41", "FM mic gain", {M_LOW, M_MID, M_HI, M_NULL},
		 "", {41,0,0,0}, 0},
	{ "42", "FM sub-tone type", {M_BURST, M_CONT, M_NULL},
		 "", {42,0,0,0}, 0},
	{ "43", "Auto repeater offset", {M_OFF, M_ON, M_NULL},
		 "", {43,0,0,0}, 0},
	{ "44", "TX hold; 1750Hz tone", {M_OFF, M_ON, M_NULL},
		 "", {44,0,0,0}, 0},
	{ "45A", "DTMF: Memory", {M_TBD, M_NULL},
		 "", {45,1,0,0}, -1},
	{ "45B", "DTMF: TX speed", {M_FAST, M_SLOW, M_NULL},
		 "", {45,2,0,0}, 0},
	{ "45C", "DTMF: Pause duration", {M_TBD, M_NULL},
		 "", {45,3,0,0}, 0},
	{ "45D", "DTMF: Mic control", {M_OFF, M_ON, M_NULL},
		 "", {45,4,0,0}, 0},
	{ "46", "TNC: Main/Sub", {M_MAIN, M_SUB, M_NULL},
		 "", {46,0,0,0}, 0},
	{ "47", "Data transfer rate; Built-in TNC", {M_TBD, M_NULL},
		 "", {47,0,0,0}, 0},
	{ "48", "DCD sense", {M_TNC_BAND, M_MAIN_SUB, M_NULL},
		 "", {48,0,0,0}, 0},
	{ "49A", "Packet Cluster: Tune", {M_AUTO, M_MAN, M_NULL},
		 "", {49,1,0,0}, 0},
	{ "49B", "Packet Cluster: RX confirmation tone", {M_OFF, M_MORSE, M_VOICE, M_NULL},
		 "", {49,2,0,0}, 0},
	{ "50A", "TNC: filter bandwidth", {M_OFF, M_ON, M_NULL},
		 "", {50,1,0,0}, 0},
	{ "50B", "TNC: AF input level", {M_TBD, M_NULL},
		 "", {50,2,0,0}, 0},
	{ "50C", "TNC: Main band AF output level", {M_TBD, M_NULL},
		 "", {50,3,0,0}, 0},
	{ "50D", "TNC: Sub band AF output level", {M_TBD, M_NULL},
		 "", {50,4,0,0}, 0},
	{ "50E", "TNC: External", {M_MAIN, M_SUB, M_NULL},
		 "", {50,5,0,0}, 0},
	{ "50F", "TNC: Ext. Data transfer rate", {M_TBD, M_NULL},
		 "", {50,6,0,0}, 0},
	{ "51A", "Front panel PF key program", {M_TBD, M_TBD, M_NULL},
		 "", {51,1,0,0}, 0},
	{ "51B", "Mic key program: PF1", {M_TBD, M_TBD, M_NULL},
		 "", {51,2,0,0}, 0},
	{ "51C", "Mic key program: PF2", {M_TBD, M_TBD, M_NULL},
		 "", {51,3,0,0}, 0},
	{ "51D", "Mic key program: PF3", {M_TBD, M_TBD, M_NULL},
		 "", {51,4,0,0}, 0},
	{ "51E", "Mic key program: PF4", {M_TBD, M_TBD, M_NULL},
		 "", {51,5,0,0}, 0},
	{ "52", "Settings copy to another transceiver", {M_OFF, M_ON, M_NULL},
		 "", {52,0,0,0}, 0},
	{ "53", "Settings Copy to VFO", {M_OFF, M_ON, M_NULL},
		 "", {53,0,0,0}, 0},
	{ "54", "TX inhibit", {M_OFF, M_ON, M_NULL},
		 "", {54,0,0,0}, 0},
	{ "55", "Packet operation", {M_OFF, M_ON, M_NULL},
		 "", {55,0,0}, 0},
	{ "56", "COM connector parameters", {M_TBD, M_NULL},
		 "", {56,0,0,0}, 0},
	{ "57", "Auto power off", {M_OFF, M_ON, M_NULL},
		 "", {57,0,0,0}, 0},
	{ "58", "Detachable-panel Display font in easy operation mode", {M_FONT1, M_FONT1, M_NULL},
		 "", {58,0,0,0}, 0},
	{ "59", "Panel display contrast", {M_TBD, M_NULL},
		 "", {59,0,0,0}, 0},
	{ "60", "Detachable-panel display reversal", {M_TBD, M_NULL},
		 "", {60,0,0,0}, 0},
	{ "61A", "Repeater mode select", {M_OFF, M_LOCKED, M_CROSS, M_NULL},
		 "", {61,1,0,0}, 0},
	{ "61B", "TX hold; repeater", {M_OFF, M_ON, M_NULL},
		 "", {61,2,0,0}, 0},
	{ "61C", "Remote Control ID code", {M_NUM, M_NULL},
		 "", {61,3,0,0}, 0},
	{ "61D", "Remote control acknowledge", {M_OFF, M_ON, M_NULL},
		 "", {61,4,0,0}, 0},
	{ "61E", "Remote control", {M_OFF, M_ON, M_NULL},
		 "", {61,5,0,0}, 0},
	{ "62A", "Commander callsign", {M_TEXT, M_NULL},
		 "no call", {62,1,0,0}, -1},
	{ "62B", "Transporter callsign", {M_TEXT, M_NULL},
		 "no call", {62,2,0,0}, -1},
	{ "62C", "Sky Command tone frequency", {M_TBD, M_NULL},
		 "", {62,3,0,0}, 0},
	{ "62D", "Sky command communication speed", {M_TBD, M_NULL},
		 "", {62,4,0,0}, 0},
	{ "62E", "Transceiver define", {M_OFF, M_CLIENT, M_COMMANDER, M_TRANSPORTER, M_NULL},
		 "", {62,5,0,0}, 0},
	{ NULL, NULL, {M_NULL, M_NULL}, "",{ 0,0,0,0}, 0}
};

// End ts2k_mdata.c
