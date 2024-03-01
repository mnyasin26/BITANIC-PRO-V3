#pragma once

//<File !Start!>
// FILE: [builder-win-x64-0.17.b27_GSLC.h]
// Created by GUIslice Builder version: [0.17.b27]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "image.h"
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XGraph.h"
#include "elem/XListbox.h"
#include "elem/XProgress.h"
#include "elem/XTogglebtn.h"
#include "elem/XCheckbox.h"
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
// #if defined(DRV_DISP_TFT_ESPI)
//   #error E_PROJECT_OPTIONS tab->Graphics Library should be TFT_eSPI
// #endif
#include <Adafruit_GFX.h>
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
#define IMG_LOGO "/Logo.bmp"
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum
{
  Dashboard,
  SplashScreen,
  wifiConnecting,
  wifiConnected,
  wifiNotConnected,
  continueNotWiFi,
  commandReceived
};
enum
{
  E_ELEM_BOX1,
  E_ELEM_BOX11,
  E_ELEM_BOX12,
  E_ELEM_BOX13,
  E_ELEM_BOX14,
  E_ELEM_BOX3,
  E_ELEM_BOX4,
  E_ELEM_GRAPH3,
  E_ELEM_GRAPH4,
  E_ELEM_IMAGE3,
  E_ELEM_LISTBOX1,
  E_ELEM_PROGRESS2,
  E_ELEM_TEXT1,
  E_ELEM_TEXT10,
  E_ELEM_TEXT11,
  E_ELEM_TEXT12,
  E_ELEM_TEXT13,
  E_ELEM_TEXT14,
  E_ELEM_TEXT2,
  E_ELEM_TEXT22,
  E_ELEM_TEXT23,
  E_ELEM_TEXT24,
  E_ELEM_TEXT25,
  E_ELEM_TEXT3,
  E_ELEM_TEXT31,
  E_ELEM_TEXT32,
  E_ELEM_TEXT33,
  E_ELEM_TEXT34,
  E_ELEM_TEXT35,
  E_ELEM_TEXT36,
  E_ELEM_TEXT37,
  E_ELEM_TEXT38,
  E_ELEM_TEXT39,
  E_ELEM_TEXT4,
  E_ELEM_TEXT5,
  E_ELEM_TEXT6,
  E_ELEM_TEXT8,
  E_ELEM_TEXT9,
  E_ELEM_TOGGLE1,
  E_ELEM_TOGGLE2,
  E_ELEM_TOGGLE3,
  E_ELEM_TOGGLE4
};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum
{
  E_BUILTIN10X16,
  E_BUILTIN5X8,
  MAX_FONT
};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE 7

#define MAX_ELEM_Dashboard 27                     // # Elems total on page
#define MAX_ELEM_Dashboard_RAM MAX_ELEM_Dashboard // # Elems in RAM

#define MAX_ELEM_SplashScreen 2                         // # Elems total on page
#define MAX_ELEM_SplashScreen_RAM MAX_ELEM_SplashScreen // # Elems in RAM

#define MAX_ELEM_wifiConnecting 3                           // # Elems total on page
#define MAX_ELEM_wifiConnecting_RAM MAX_ELEM_wifiConnecting // # Elems in RAM

#define MAX_ELEM_wifiConnected 1                          // # Elems total on page
#define MAX_ELEM_wifiConnected_RAM MAX_ELEM_wifiConnected // # Elems in RAM

#define MAX_ELEM_wifiNotConnected 5                             // # Elems total on page
#define MAX_ELEM_wifiNotConnected_RAM MAX_ELEM_wifiNotConnected // # Elems in RAM

#define MAX_ELEM_continueNotWiFi 3                            // # Elems total on page
#define MAX_ELEM_continueNotWiFi_RAM MAX_ELEM_continueNotWiFi // # Elems in RAM

#define MAX_ELEM_commandReceived 1                            // # Elems total on page
#define MAX_ELEM_commandReceived_RAM MAX_ELEM_commandReceived // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui m_gui;
gslc_tsDriver m_drv;
gslc_tsFont m_asFont[MAX_FONT];
gslc_tsPage m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem m_asPage1Elem[MAX_ELEM_Dashboard_RAM];
gslc_tsElemRef m_asPage1ElemRef[MAX_ELEM_Dashboard];
gslc_tsElem m_asPage2Elem[MAX_ELEM_SplashScreen_RAM];
gslc_tsElemRef m_asPage2ElemRef[MAX_ELEM_SplashScreen];
gslc_tsElem m_asPage4Elem[MAX_ELEM_wifiConnecting_RAM];
gslc_tsElemRef m_asPage4ElemRef[MAX_ELEM_wifiConnecting];
gslc_tsElem m_asPage5Elem[MAX_ELEM_wifiConnected_RAM];
gslc_tsElemRef m_asPage5ElemRef[MAX_ELEM_wifiConnected];
gslc_tsElem m_asPage6Elem[MAX_ELEM_wifiNotConnected_RAM];
gslc_tsElemRef m_asPage6ElemRef[MAX_ELEM_wifiNotConnected];
gslc_tsElem m_asPage7Elem[MAX_ELEM_continueNotWiFi_RAM];
gslc_tsElemRef m_asPage7ElemRef[MAX_ELEM_continueNotWiFi];
gslc_tsElem m_asPage8Elem[MAX_ELEM_commandReceived_RAM];
gslc_tsElemRef m_asPage8ElemRef[MAX_ELEM_commandReceived];
gslc_tsXTogglebtn m_asXToggle1;
gslc_tsXListbox m_sListbox1;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char m_acListboxBuf1[159 + XLISTBOX_BUF_OH_R];
gslc_tsXTogglebtn m_asXToggle2;
gslc_tsXTogglebtn m_asXToggle3;
gslc_tsXTogglebtn m_asXToggle4;
gslc_tsXGraph m_sGraph3;
int16_t m_anGraphBuf3[60]; // NRows=60
gslc_tsXProgress m_sXBarGauge2;
gslc_tsXGraph m_sGraph4;
int16_t m_anGraphBuf4[60]; // NRows=60

#define MAX_STR 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef *m_pElemGraph3;
extern gslc_tsElemRef *m_pElemGraph4;
extern gslc_tsElemRef *m_pElemListbox1;
extern gslc_tsElemRef *m_pElemProgress2;
extern gslc_tsElemRef *m_pElemToggle1;
extern gslc_tsElemRef *m_pElemToggle2;
extern gslc_tsElemRef *m_pElemToggle3;
extern gslc_tsElemRef *m_pElemToggle4;
extern gslc_tsElemRef *m_pListSlider1;

extern gslc_tsElemRef *m_bar1Signal;
extern gslc_tsElemRef *m_bar2Signal;
extern gslc_tsElemRef *m_bar3Signal;

extern gslc_tsElemRef *m_date;
extern gslc_tsElemRef *m_time;

extern gslc_tsElemRef *m_suhu;
extern gslc_tsElemRef *m_humidity;

extern gslc_tsElemRef *test;


extern gslc_tsElemRef *t_SSID;
extern gslc_tsElemRef *t_loading1;
extern gslc_tsElemRef *t_loading2;
extern gslc_tsElemRef *t_APName;
extern gslc_tsElemRef *t_timeout;
extern gslc_tsElemRef *t_toConfig;
extern gslc_tsElemRef *t_connected;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY);
bool CbCheckbox(void *pvGui, void *pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void *pvGui, void *pvElemRef, gslc_teRedrawType eRedraw);
bool CbKeypad(void *pvGui, void *pvElemRef, int16_t nState, void *pvData);
bool CbListbox(void *pvGui, void *pvElemRef, int16_t nSelId);
bool CbSlidePos(void *pvGui, void *pvElemRef, int16_t nPos);
bool CbSpinner(void *pvGui, void *pvElemRef, int16_t nState, void *pvData);
bool CbTickScanner(void *pvGui, void *pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef *pElemRef = NULL;

  if (!gslc_Init(&m_gui, &m_drv, m_asPage, MAX_PAGE, m_asFont, MAX_FONT))
  {
    return;
  }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
  //<Load_Fonts !Start!>
  if (!gslc_FontSet(&m_gui, E_BUILTIN10X16, GSLC_FONTREF_PTR, NULL, 2))
  {
    return;
  }
  if (!gslc_FontSet(&m_gui, E_BUILTIN5X8, GSLC_FONTREF_PTR, NULL, 1))
  {
    return;
  }
  //<Load_Fonts !End!>

  //<InitGUI !Start!>
  gslc_PageAdd(&m_gui, Dashboard, m_asPage1Elem, MAX_ELEM_Dashboard_RAM, m_asPage1ElemRef, MAX_ELEM_Dashboard);
  gslc_PageAdd(&m_gui, SplashScreen, m_asPage2Elem, MAX_ELEM_SplashScreen_RAM, m_asPage2ElemRef, MAX_ELEM_SplashScreen);
  gslc_PageAdd(&m_gui, wifiConnecting, m_asPage4Elem, MAX_ELEM_wifiConnecting_RAM, m_asPage4ElemRef, MAX_ELEM_wifiConnecting);
  gslc_PageAdd(&m_gui, wifiConnected, m_asPage5Elem, MAX_ELEM_wifiConnected_RAM, m_asPage5ElemRef, MAX_ELEM_wifiConnected);
  gslc_PageAdd(&m_gui, wifiNotConnected, m_asPage6Elem, MAX_ELEM_wifiNotConnected_RAM, m_asPage6ElemRef, MAX_ELEM_wifiNotConnected);
  gslc_PageAdd(&m_gui, continueNotWiFi, m_asPage7Elem, MAX_ELEM_continueNotWiFi_RAM, m_asPage7ElemRef, MAX_ELEM_continueNotWiFi);
  gslc_PageAdd(&m_gui, commandReceived, m_asPage8Elem, MAX_ELEM_commandReceived_RAM, m_asPage8ElemRef, MAX_ELEM_commandReceived);

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui, SplashScreen);

  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui, GSLC_COL_BLACK);

  // -----------------------------------
  // PAGE: Dashboard

  //  // Create E_ELEM_BOX14 box
  pElemRef = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX14, Dashboard, (gslc_tsRect){17, 166, 212, 68});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);

  // Create E_ELEM_BOX3 box
  pElemRef = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX3, Dashboard, (gslc_tsRect){17, 42, 212, 120});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);

  // Create E_ELEM_BOX1 box
  pElemRef = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX1, Dashboard, (gslc_tsRect){233, 42, 68, 155});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_GRAY, GSLC_COL_GRAY_DK2, GSLC_COL_GRAY_DK2);

  // Create toggle button E_ELEM_TOGGLE1
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui, E_ELEM_TOGGLE1, Dashboard, &m_asXToggle1,
                                       (gslc_tsRect){249, 59, 35, 20}, GSLC_COL_GRAY, GSLC_COL_GREEN_LT1, GSLC_COL_GRAY_LT3,
                                       false, false, &CbBtnCommon);
  m_pElemToggle1 = pElemRef;

  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui, E_ELEM_LISTBOX1, Dashboard, &m_sListbox1,
                                     (gslc_tsRect){22, 55, 202, 70}, E_BUILTIN5X8,
                                     (uint8_t *)&m_acListboxBuf1, sizeof(m_acListboxBuf1), 1);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 5, 1); // 5 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, 180, 10);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 5);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_BLUE, GSLC_COL_BLACK, GSLC_COL_BLACK);
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemXListboxItemsSetGap(&m_gui, pElemRef, 2, GSLC_COL_BLACK);
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "Tanggal    Waktu Durasi   Tipe");

  gslc_ElemSetFrameEn(&m_gui, pElemRef, true);
  m_pElemListbox1 = pElemRef;

  // Create E_ELEM_TEXT1 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT1, Dashboard, (gslc_tsRect){246, 49, 42, 8},
                                (char *)"Lahan 1", 0, E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);

  // Create E_ELEM_TEXT2 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT2, Dashboard, (gslc_tsRect){80, 45, 90, 8},
                                (char *)"Jadwal Terdekat", 0, E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);

  // Create E_ELEM_TEXT3 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT3, Dashboard, (gslc_tsRect){246, 85, 42, 8},
                                (char *)"Lahan 2", 0, E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);

  // Create toggle button E_ELEM_TOGGLE2
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui, E_ELEM_TOGGLE2, Dashboard, &m_asXToggle2,
                                       (gslc_tsRect){249, 95, 35, 20}, GSLC_COL_GRAY, GSLC_COL_GREEN_LT1, GSLC_COL_GRAY_LT3,
                                       false, false, &CbBtnCommon);
  m_pElemToggle2 = pElemRef;

  // Create E_ELEM_TEXT4 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT4, Dashboard, (gslc_tsRect){246, 121, 42, 8},
                                (char *)"Lahan 3", 0, E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);

  // Create toggle button E_ELEM_TOGGLE3
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui, E_ELEM_TOGGLE3, Dashboard, &m_asXToggle3,
                                       (gslc_tsRect){249, 131, 35, 20}, GSLC_COL_GRAY, GSLC_COL_GREEN_LT1, GSLC_COL_GRAY_LT3,
                                       false, false, &CbBtnCommon);
  m_pElemToggle3 = pElemRef;

  // Create E_ELEM_TEXT5 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT5, Dashboard, (gslc_tsRect){246, 157, 42, 8},
                                (char *)"Lahan 4", 0, E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);

  // Create toggle button E_ELEM_TOGGLE4
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui, E_ELEM_TOGGLE4, Dashboard, &m_asXToggle4,
                                       (gslc_tsRect){249, 167, 35, 20}, GSLC_COL_GRAY, GSLC_COL_GREEN_LT1, GSLC_COL_GRAY_LT3,
                                       false, false, &CbBtnCommon);
  m_pElemToggle4 = pElemRef;

  // Create graph E_ELEM_GRAPH3
  pElemRef = gslc_ElemXGraphCreate(&m_gui, E_ELEM_GRAPH3, Dashboard,
                                   &m_sGraph3, (gslc_tsRect){96, 171, 60, 50}, E_BUILTIN5X8, (int16_t *)&m_anGraphBuf3,
                                   60, GSLC_COL_BROWN);
  gslc_ElemXGraphSetStyle(&m_gui, pElemRef, GSLCX_GRAPH_STYLE_FILL, 5);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_BLACK, GSLC_COL_BLACK, GSLC_COL_BLACK);
  m_pElemGraph3 = pElemRef;

  // Create progress bar E_ELEM_PROGRESS2
  pElemRef = gslc_ElemXProgressCreate(&m_gui, E_ELEM_PROGRESS2, Dashboard, &m_sXBarGauge2,
                                      (gslc_tsRect){22, 141, 202, 12}, 0, 100, 0, GSLC_COL_GREEN, false);
  m_pElemProgress2 = pElemRef;

  // Create E_ELEM_TEXT6 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT6, Dashboard, (gslc_tsRect){35, 129, 174, 8},
                                (char *)"Progress Penyiraman/Pemupukan", 0, E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);

  // Create graph E_ELEM_GRAPH4
  pElemRef = gslc_ElemXGraphCreate(&m_gui, E_ELEM_GRAPH4, Dashboard,
                                   &m_sGraph4, (gslc_tsRect){161, 171, 60, 50}, E_BUILTIN5X8, (int16_t *)&m_anGraphBuf4,
                                   60, GSLC_COL_BLUE_DK1);
  gslc_ElemXGraphSetStyle(&m_gui, pElemRef, GSLCX_GRAPH_STYLE_FILL, 5);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_BLACK, GSLC_COL_BLACK, GSLC_COL_BLACK);
  m_pElemGraph4 = pElemRef;

  // Create E_ELEM_TEXT8 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT8, Dashboard, (gslc_tsRect){113, 223, 24, 8},
                                (char *)"Suhu", 0, E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);

  // Create E_ELEM_TEXT9 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT9, Dashboard, (gslc_tsRect){160, 223, 60, 8},
                                (char *)"Kelembapan", 0, E_BUILTIN5X8);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);

  // Create E_ELEM_TEXT10 text label
  m_suhu = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT10, Dashboard, (gslc_tsRect){27, 182, 60, 16},
                              (char *)"23.3C", 10, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, m_suhu, false);

  // Create E_ELEM_TEXT11 text label
  m_humidity = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT11, Dashboard, (gslc_tsRect){26, 207, 60, 16},
                                  (char *)"10.5%", 10, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, m_humidity, false);

  // Create E_ELEM_BOX4 box
  pElemRef = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX4, Dashboard, (gslc_tsRect){17, 7, 285, 30});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);

  // Create E_ELEM_TEXT12 text label
  m_date = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT12, Dashboard, (gslc_tsRect){32, 15, 120, 16},
                              (char *)"26/02/2024", 12, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, m_date, false);
  gslc_ElemSetTxtCol(&m_gui, m_date, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT13 text label
  m_time = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT13, Dashboard, (gslc_tsRect){163, 15, 96, 16},
                              (char *)"13:34:48", 10, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, m_time, false);
  gslc_ElemSetTxtCol(&m_gui, m_time, GSLC_COL_WHITE);

  // Create E_ELEM_BOX11 box
  m_bar1Signal = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX11, Dashboard, (gslc_tsRect){272, 27, 3, 2});
  gslc_ElemSetCol(&m_gui, m_bar1Signal, GSLC_COL_GREEN_LT1, GSLC_COL_GREEN_LT1, GSLC_COL_GREEN_LT1);

  // Create E_ELEM_BOX12 box
  m_bar2Signal = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX12, Dashboard, (gslc_tsRect){278, 21, 3, 8});
  gslc_ElemSetCol(&m_gui, m_bar2Signal, GSLC_COL_GREEN_LT1, GSLC_COL_GREEN_LT1, GSLC_COL_GREEN_LT1);

  // Create E_ELEM_BOX13 box
  m_bar3Signal = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX13, Dashboard, (gslc_tsRect){284, 15, 3, 14});
  gslc_ElemSetCol(&m_gui, m_bar3Signal, GSLC_COL_GREEN_LT1, GSLC_COL_GREEN_LT1, GSLC_COL_GREEN_LT1);

  // -----------------------------------
  // PAGE: SplashScreen

  // Create E_ELEM_TEXT14 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT14, SplashScreen, (gslc_tsRect){22, 210, 276, 16},
                                (char *)"Powered by PT Makerindo", 0, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_WHITE);

  // Create E_ELEM_IMAGE3 using Image
  pElemRef = gslc_ElemCreateImg(&m_gui, E_ELEM_IMAGE3, SplashScreen, (gslc_tsRect){20, 41, 280, 126},
                                gslc_GetImageFromProg((const unsigned char *)Logo, GSLC_IMGREF_FMT_BMP24));
  test = pElemRef;

  // -----------------------------------
  // PAGE: wifiConnecting

  // Create E_ELEM_TEXT22 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT22, wifiConnecting, (gslc_tsRect){70, 72, 180, 16},
                                (char *)"Connecting WiFi", 0, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT23 text label
  t_SSID = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT23, wifiConnecting, (gslc_tsRect){70, 97, 180, 16},
                                (char *)"\"makerindo2019\"", 30, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, t_SSID, GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui, t_SSID, false);
  gslc_ElemSetTxtCol(&m_gui, t_SSID, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT24 text label
  t_loading1 = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT24, wifiConnecting, (gslc_tsRect){142, 154, 36, 16},
                                (char *)"...", 5, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, t_loading1, GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui, t_loading1, false);
  gslc_ElemSetTxtCol(&m_gui, t_loading1, GSLC_COL_WHITE);

  // -----------------------------------
  // PAGE: wifiConnected

  // Create E_ELEM_TEXT25 text label
  t_connected = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT25, wifiConnected, (gslc_tsRect){76, 107, 168, 16},
                                (char *)"WiFi Connected", 25, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, t_connected, false);
  gslc_ElemSetTxtCol(&m_gui, t_connected, GSLC_COL_WHITE);

  // -----------------------------------
  // PAGE: wifiNotConnected

  // Create E_ELEM_TEXT31 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT31, wifiNotConnected, (gslc_tsRect){52, 38, 216, 16},
                                (char *)"WiFi Not Connected", 0, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT32 text label
  t_APName = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT32, wifiNotConnected, (gslc_tsRect){40, 94, 240, 16},
                                (char *)"Connect \"BT_SETTING\"", 30, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, t_APName, GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui, t_APName, false);
  gslc_ElemSetTxtCol(&m_gui, t_APName, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT33 text label
  t_toConfig = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT33, wifiNotConnected, (gslc_tsRect){58, 119, 204, 16},
                                (char *)"to Configure Wifi A", 30, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, t_toConfig, GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui, t_toConfig, false);
  gslc_ElemSetTxtCol(&m_gui, t_toConfig, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT34 text label
  t_timeout = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT34, wifiNotConnected, (gslc_tsRect){34, 158, 252, 16},
                                (char *)"timeout in 60 seconds", 30, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, t_timeout, false);
  gslc_ElemSetTxtCol(&m_gui, t_timeout, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT38 text label
  t_loading2 = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT38, wifiNotConnected, (gslc_tsRect){142, 193, 36, 16},
                                (char *)"...", 10, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, t_loading2, GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui, t_loading2, false);
  gslc_ElemSetTxtCol(&m_gui, t_loading2, GSLC_COL_WHITE);

  // -----------------------------------
  // PAGE: continueNotWiFi

  // Create E_ELEM_TEXT35 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT35, continueNotWiFi, (gslc_tsRect){34, 74, 252, 16},
                                (char *)"Continue Without WiFi", 0, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT36 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT36, continueNotWiFi, (gslc_tsRect){82, 126, 156, 16},
                                (char *)"Some Features", 0, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_WHITE);

  // Create E_ELEM_TEXT37 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT37, continueNotWiFi, (gslc_tsRect){52, 151, 216, 16},
                                (char *)"Will be Restricted", 0, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_WHITE);

  // -----------------------------------
  // PAGE: commandReceived

  // Create E_ELEM_TEXT39 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT39, commandReceived, (gslc_tsRect){67, 111, 186, 16},
                                (char *)"Command Received", 0, E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui, pElemRef, false);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_WHITE);

  //<InitGUI !End!>

  //<Startup !Start!>
  //<Startup !End!>
}

#endif // end _GUISLICE_GEN_H
