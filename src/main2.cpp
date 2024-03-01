// //<App !Start!>
// // FILE: [builder-win-x64-0.17.b27.ino]
// // Created by GUIslice Builder version: [0.17.b27]
// //
// // GUIslice Builder Generated File
// //
// // For the latest guides, updates and support view:
// // https://github.com/ImpulseAdventure/GUIslice
// //
// //<App !End!>

// // ------------------------------------------------
// // Headers to include
// // ------------------------------------------------
// #include "builder-win-x64-0.17.b27_GSLC.h"
// #include <WiFiManager.h>

// // ------------------------------------------------
// // Program Globals
// // ------------------------------------------------

// // Save some element references for direct access
// //<Save_References !Start!>
// gslc_tsElemRef *m_pElemGraph3 = NULL;
// gslc_tsElemRef *m_pElemGraph4 = NULL;
// gslc_tsElemRef *m_pElemListbox1 = NULL;
// gslc_tsElemRef *m_pElemProgress2 = NULL;
// gslc_tsElemRef *m_pElemToggle1 = NULL;
// gslc_tsElemRef *m_pElemToggle2 = NULL;
// gslc_tsElemRef *m_pElemToggle3 = NULL;
// gslc_tsElemRef *m_pElemToggle4 = NULL;
// gslc_tsElemRef *m_pListSlider1 = NULL;
// //<Save_References !End!>

// int pos = 0;

// // Define debug message function
// static int16_t DebugOut(char ch)
// {
//     if (ch == (char)'\n')
//         DEBUG_PRINTLN("");
//     else
//         Serial.write(ch);
//     return 0;
// }

// // ------------------------------------------------
// // Callback Methods
// // ------------------------------------------------
// // Common Button callback
// bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY)
// {
//     // Typecast the parameters to match the GUI and element types
//     gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
//     gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
//     gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

//     if (eTouch == GSLC_TOUCH_UP_IN)
//     {
//         // From the element's ID we can determine which button was pressed.
//         switch (pElem->nId)
//         {
//             //<Button Enums !Start!>
//         case E_ELEM_TOGGLE1:
//             // TODO Add code for Toggle button ON/OFF state
//             if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle1))
//             {
//                 ;
//             }
//             break;
//         case E_ELEM_TOGGLE2:
//             // TODO Add code for Toggle button ON/OFF state
//             if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2))
//             {
//                 ;
//             }
//             break;
//         case E_ELEM_TOGGLE3:
//             // TODO Add code for Toggle button ON/OFF state
//             if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle3))
//             {
//                 ;
//             }
//             break;
//         case E_ELEM_TOGGLE4:
//             // TODO Add code for Toggle button ON/OFF state
//             if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle4))
//             {
//                 ;
//             }
//             break;
//             //<Button Enums !End!>
//         default:
//             break;
//         }
//     }
//     return true;
// }
// // Checkbox / radio callbacks
// // - Creating a callback function is optional, but doing so enables you to
// //   detect changes in the state of the elements.
// bool CbCheckbox(void *pvGui, void *pvElemRef, int16_t nSelId, bool bState)
// {
//     gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
//     gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
//     gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
//     if (pElemRef == NULL)
//     {
//         return false;
//     }

//     boolean bChecked = gslc_ElemXCheckboxGetState(pGui, pElemRef);

//     // Determine which element issued the callback
//     switch (pElem->nId)
//     {
//         //<Checkbox Enums !Start!>

//         //<Checkbox Enums !End!>
//     default:
//         break;
//     } // switch

//     return true;
// }
// //<Keypad Callback !Start!>
// //<Keypad Callback !End!>
// //<Spinner Callback !Start!>
// //<Spinner Callback !End!>
// bool CbListbox(void *pvGui, void *pvElemRef, int16_t nSelId)
// {
//     gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
//     gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
//     gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
//     char acTxt[MAX_STR + 1];

//     if (pElemRef == NULL)
//     {
//         return false;
//     }

//     // From the element's ID we can determine which listbox was active.
//     switch (pElem->nId)
//     {
//         //<Listbox Enums !Start!>
//     case E_ELEM_LISTBOX1:
//         if (nSelId != XLISTBOX_SEL_NONE)
//         {
//             gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
//         }
//         break;

//         //<Listbox Enums !End!>
//     default:
//         break;
//     }
//     return true;
// }
// //<Draw Callback !Start!>
// //<Draw Callback !End!>

// // // Callback function for when a slider's position has been updated
// // bool CbSlidePos(void *pvGui, void *pvElemRef, int16_t nPos)
// // {
// //     gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
// //     gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
// //     gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
// //     int16_t nVal;

// //     // From the element's ID we can determine which slider was updated.
// //     switch (pElem->nId)
// //     {
// //         //<Slider Enums !Start!>
// //     case E_LISTSCROLL1:
// //         // Fetch the slider position
// //         nVal = gslc_ElemXSliderGetPos(pGui, m_pListSlider1);
// //         break;

// //         //<Slider Enums !End!>
// //     default:
// //         break;
// //     }

// //     return true;
// // }
// //<Tick Callback !Start!>
// //<Tick Callback !End!>

// void setup()
// {
//     // ------------------------------------------------
//     // Initialize
//     // ------------------------------------------------
//     Serial.begin(9600);
//     // Wait for USB Serial
//     // delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

//     gslc_InitDebug(&DebugOut);

//     // ------------------------------------------------
//     // Create graphic elements
//     // ------------------------------------------------
//     InitGUIslice_gen();

//     // gslc_ElemXListboxAddItem(&m_gui, m_pElemListbox1, "tes");
//     // gslc_ElemXListboxAddItem(&m_gui, m_pElemListbox1, "12/20/2020 12:00:00 AM");
//     // delay(5000);

//     // gslc_ElemXListboxde
//     // gslc_ElemXListboxDeleteItemAt(&m_gui, m_pElemListbox1, 4);
//     // gslc_ElemXListboxDeleteItemAt(&m_gui, m_pElemListbox1, 5);
//     // gslc_ElemXListboxSetSel
//     // tft.setRotation(2);
//     gslc_GuiRotate(&m_gui, 3);

// }

// bool isDeleted = false;
// // -----------------------------------
// // Main event loop
// // -----------------------------------
// void loop()
// {

//     // ------------------------------------------------
//     // Update GUI Elements
//     // ------------------------------------------------

//     // TODO - Add update code for any text, gauges, or sliders

//     pos = (pos + 10) % 100;
//     gslc_ElemXProgressSetVal(&m_gui, m_pElemProgress2, pos);

//     gslc_ElemXTogglebtnToggleState(&m_gui, m_pElemToggle1);
//     gslc_ElemXTogglebtnSetState(&m_gui, m_pElemToggle2, true);

//     // gslc_ELemXGrap
//     gslc_ElemXGraphAdd(&m_gui, m_pElemGraph3, random(0,100));
//     gslc_ElemXGraphAdd(&m_gui, m_pElemGraph4, random(0,100));
//     // gslc_ElemXGraphAdd(&m_gui, m_pElemGraph3, random(10,90));

//     // ------------------------------------------------
//     // Periodically call GUIslice update function
//     // ------------------------------------------------

//     gslc_Update(&m_gui);

//     if (millis() > 5000 && isDeleted == false)
//     {
//         gslc_ElemXListboxDeleteItemAt(&m_gui, m_pElemListbox1, 2);
//         isDeleted = true;
//         // gslc_ElemXListboxDeleteItemAt(&m_gui, m_pElemListbox1, 5);
//         // gslc_ElemXListboxSetSel(&m_gui, m_pElemListbox1, 1);
//     }

//     delay(500);
// }
