#include "displayTFT.h"
#include "builder-win-x64-0.17.b27_GSLC.h"

gslc_tsElemRef *m_pElemGraph3 = NULL;
gslc_tsElemRef *m_pElemGraph4 = NULL;
gslc_tsElemRef *m_pElemListbox1 = NULL;
gslc_tsElemRef *m_pElemProgress2 = NULL;
gslc_tsElemRef *m_pElemToggle1 = NULL;
gslc_tsElemRef *m_pElemToggle2 = NULL;
gslc_tsElemRef *m_pElemToggle3 = NULL;
gslc_tsElemRef *m_pElemToggle4 = NULL;
gslc_tsElemRef *m_pListSlider1 = NULL;

gslc_tsElemRef *m_bar1Signal = NULL;
gslc_tsElemRef *m_bar2Signal = NULL;
gslc_tsElemRef *m_bar3Signal = NULL;

gslc_tsElemRef *m_date = NULL;
gslc_tsElemRef *m_time = NULL;

gslc_tsElemRef *m_suhu = NULL;
gslc_tsElemRef *m_humidity = NULL;
gslc_tsElemRef *test = NULL;

gslc_tsElemRef *t_SSID;
gslc_tsElemRef *t_loading1;
gslc_tsElemRef *t_loading2;
gslc_tsElemRef *t_APName;
gslc_tsElemRef *t_timeout;
gslc_tsElemRef *t_toConfig;
gslc_tsElemRef *t_connected;

void DisplayTFT::setSSIDText(String t)
{
    gslc_ElemSetTxtStr(&m_gui, t_SSID, t.c_str());
}

void DisplayTFT::setAPNameText(String t)
{
    gslc_ElemSetTxtStr(&m_gui, t_APName, t.c_str());
}

void DisplayTFT::setToConfigText()
{
    gslc_ElemSetTxtStr(&m_gui, t_toConfig, "to Configure WiFi");
}

void DisplayTFT::loading1Text()
{
    DEBUG_PRINTLN(gslc_ElemGetTxtStr(&m_gui, t_loading1));
    DEBUG_PRINTLN(loading1Counter);
    if (loading1Counter == 0)
    {
        gslc_ElemSetTxtCol(&m_gui, t_loading1, GSLC_COL_WHITE);
        String temp = ". ";
        gslc_ElemSetTxtStr(&m_gui, t_loading1, temp.c_str());
    }
    else if (loading1Counter == 1)
    {
        String temp = ".. ";
        gslc_ElemSetTxtStr(&m_gui, t_loading1, temp.c_str());
    }
    else if (loading1Counter == 2)
    {
        String temp = "... ";
        gslc_ElemSetTxtStr(&m_gui, t_loading1, temp.c_str());
    }
    else if (loading1Counter == 3)
    {
        gslc_ElemSetTxtCol(&m_gui, t_loading1, GSLC_COL_BLACK);
        // gslc_ElemSetTxtStr(&m_gui, t_loading2, temp.c_str());
    }

    isChanged = true;
    updateAtChanged();

    if (loading1Counter == 3)
    {
        loading1Counter = 0;
    }
    else
    {
        loading1Counter++;
    }
}

void DisplayTFT::reDrawWiFiConnected()
{
    DEBUG_PRINTLN(gslc_ElemGetTxtStr(&m_gui, t_connected));
    gslc_ElemSetRedraw(&m_gui, t_connected, GSLC_REDRAW_INC);
}

void DisplayTFT::loading2Text()
{
    DEBUG_PRINTLN(gslc_ElemGetTxtStr(&m_gui, t_loading2));
    DEBUG_PRINTLN(loading2Counter);
    if (loading2Counter == 0)
    {
        gslc_ElemSetTxtCol(&m_gui, t_loading2, GSLC_COL_WHITE);
        String temp = ". ";
        gslc_ElemSetTxtStr(&m_gui, t_loading2, temp.c_str());
    }
    else if (loading2Counter == 1)
    {
        String temp = ".. ";
        gslc_ElemSetTxtStr(&m_gui, t_loading2, temp.c_str());
    }
    else if (loading2Counter == 2)
    {
        String temp = "... ";
        gslc_ElemSetTxtStr(&m_gui, t_loading2, temp.c_str());
    }
    else if (loading2Counter == 3)
    {
        gslc_ElemSetTxtCol(&m_gui, t_loading2, GSLC_COL_BLACK);
        // gslc_ElemSetTxtStr(&m_gui, t_loading2, temp.c_str());
    }

    isChanged = true;
    updateAtChanged();

    if (loading2Counter == 3)
    {
        loading2Counter = 0;
    }
    else
    {
        loading2Counter++;
    }
}

void DisplayTFT::setTimeoutText(String t)
{
    gslc_ElemSetTxtStr(&m_gui, t_timeout, ((String)("timeout in " + t + " seconds")).c_str());
}

void DisplayTFT::changePage(int page)
{
    gslc_SetPageCur(&m_gui, page);
    gslc_Update(&m_gui);
}

void DisplayTFT::jadwal_Add(String jadwal)
{
    gslc_ElemXListboxAddItem(&m_gui, m_pElemListbox1, jadwal.c_str());
    isChanged = true;
    updateAtChanged();
}
void DisplayTFT::jadwal_Delete(int position)
{
    gslc_ElemXListboxDeleteItemAt(&m_gui, m_pElemListbox1, position);

    isChanged = true;
    updateAtChanged();
}

int DisplayTFT::getItemNumber()
{
    return gslc_ElemXListboxGetItemCnt(&m_gui, m_pElemListbox1);
}

void DisplayTFT::setStateL1(bool state)
{
    if (stateL1 != state)
    {
        stateL1 = state;
        isChanged = true;

        gslc_ElemXTogglebtnSetState(&m_gui, m_pElemToggle1, state);
        updateAtChanged();
    }
}
void DisplayTFT::setStateL2(bool state)
{
    if (stateL2 != state)
    {
        stateL2 = state;
        isChanged = true;

        gslc_ElemXTogglebtnSetState(&m_gui, m_pElemToggle2, state);
        updateAtChanged();
    }
}
void DisplayTFT::setStateL3(bool state)
{
    if (stateL3 != state)
    {
        stateL3 = state;
        isChanged = true;

        gslc_ElemXTogglebtnSetState(&m_gui, m_pElemToggle3, state);
        updateAtChanged();
    }
}
void DisplayTFT::setStateL4(bool state)
{
    if (stateL4 != state)
    {
        stateL4 = state;
        isChanged = true;

        gslc_ElemXTogglebtnSetState(&m_gui, m_pElemToggle4, state);
        updateAtChanged();
    }
}

void DisplayTFT::setOnShceduleHighlight(bool isLighten)
{
    if (isLighten)
    {
        gslc_ElemSetCol(&m_gui, m_pElemListbox1, GSLC_COL_BLUE, GSLC_COL_BLACK, (gslc_tsColor){0, 90, 0});
        gslc_ElemXListboxSetSel(&m_gui, m_pElemListbox1, 1);
        isChanged = true;
    }
    else
    {
        gslc_ElemSetCol(&m_gui, m_pElemListbox1, GSLC_COL_BLUE, GSLC_COL_BLACK, GSLC_COL_BLACK);
        gslc_ElemXListboxSetSel(&m_gui, m_pElemListbox1, 1);
        isChanged = true;
    }

    updateAtChanged();
}

void DisplayTFT::setWiFiSignalStrength(int strength)
{
    if (wifiSignalStrength != strength)
    {
        wifiSignalStrength = strength;
        isChanged = true;

        gslc_tsColor col1;
        gslc_tsColor col2;
        gslc_tsColor col3;

        switch (strength)
        {
        case 0:
            // no signal
            col1 = GSLC_COL_GRAY_DK2;
            col2 = GSLC_COL_GRAY_DK2;
            col3 = GSLC_COL_GRAY_DK2;

            break;

        case 1:
            // 1 bar
            col1 = GSLC_COL_RED_LT1;
            col2 = GSLC_COL_GRAY_DK2;
            col3 = GSLC_COL_GRAY_DK2;
            break;

        case 2:
            // 2 bar
            col1 = GSLC_COL_YELLOW;
            col2 = GSLC_COL_YELLOW;
            col3 = GSLC_COL_GRAY_DK2;
            break;

        case 3:
            // 3 bar
            col1 = GSLC_COL_GREEN_LT1;
            col2 = GSLC_COL_GREEN_LT1;
            col3 = GSLC_COL_GREEN_LT1;
            break;

        default:
            break;
        }

        // Change Color E_ELEM_BOX11 box
        gslc_ElemSetCol(&m_gui, m_bar1Signal, col1, col1, col1);

        // Change Color E_ELEM_BOX12 box
        gslc_ElemSetCol(&m_gui, m_bar2Signal, col2, col2, col2);

        // Change Color E_ELEM_BOX13 box
        gslc_ElemSetCol(&m_gui, m_bar3Signal, col3, col3, col3);

        updateAtChanged();
    }
}

void DisplayTFT::setDate(String date)
{
    if (this->date != date)
    {
        this->date = date;
        isChanged = true;

        gslc_ElemSetTxtStr(&m_gui, m_date, date.c_str());
        updateAtChanged();
    }
}

void DisplayTFT::setTime(String time)
{
    if (this->time != time)
    {
        this->time = time;
        isChanged = true;

        gslc_ElemSetTxtStr(&m_gui, m_time, time.c_str());

        DEBUG_PRINT("time: ");
        DEBUG_PRINTLN(time);

        updateAtChanged();
    }
}

void DisplayTFT::setProgress(int progress)
{
    if (this->progress != progress)
    {
        this->progress = progress;
        isChanged = true;

        gslc_ElemXProgressSetVal(&m_gui, m_pElemProgress2, progress);
        updateAtChanged();
    }
}
void DisplayTFT::addSuhuPoint(float c)
{
    isChanged = true;
    gslc_ElemXGraphAdd(&m_gui, m_pElemGraph3, map(c * 10, 0, 1000, 0, 100));
    updateAtChanged();
}
void DisplayTFT::addHumPoint(float h)
{
    isChanged = true;
    gslc_ElemXGraphAdd(&m_gui, m_pElemGraph4, map(h * 10, 0, 1000, 0, 100));
    updateAtChanged();
}

void DisplayTFT::setSuhu(float c)
{
    if (suhu != c)
    {
        suhu = c;
        isChanged = true;

        gslc_ElemSetTxtStr(&m_gui, m_suhu, (String(c, 1) + "C").c_str());
        DEBUG_PRINT("suhu gui: ");
        DEBUG_PRINTLN(String(c, 2).c_str());

        updateAtChanged();
    }
}

void DisplayTFT::setHum(float h)
{
    if (hum != h)
    {
        hum = h;
        isChanged = true;

        gslc_ElemSetTxtStr(&m_gui, m_humidity, (String(h, 1) + "%").c_str());
        DEBUG_PRINT("hum gui: ");
        DEBUG_PRINTLN(String(h, 1).c_str());

        updateAtChanged();
    }
}

void DisplayTFT::updateAtChanged()
{
    if (isChanged)
    {
        gslc_Update(&m_gui);
        isChanged = false;
    }
}

//<App !Start!>
// FILE: [builder-win-x64-0.17.b27.ino]
// Created by GUIslice Builder version: [0.17.b27]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>

//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch)
{
    if (ch == (char)'\n')
        DEBUG_PRINTLN("");
    else
        Serial.write(ch);
    return 0;
}

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY)
{
    // Typecast the parameters to match the GUI and element types
    gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
    gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
    gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

    if (eTouch == GSLC_TOUCH_UP_IN)
    {
        // From the element's ID we can determine which button was pressed.
        switch (pElem->nId)
        {
            //<Button Enums !Start!>
        case E_ELEM_TOGGLE1:
            // TODO Add code for Toggle button ON/OFF state
            if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle1))
            {
                ;
            }
            break;
        case E_ELEM_TOGGLE2:
            // TODO Add code for Toggle button ON/OFF state
            if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2))
            {
                ;
            }
            break;
        case E_ELEM_TOGGLE3:
            // TODO Add code for Toggle button ON/OFF state
            if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle3))
            {
                ;
            }
            break;
        case E_ELEM_TOGGLE4:
            // TODO Add code for Toggle button ON/OFF state
            if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle4))
            {
                ;
            }
            break;
            //<Button Enums !End!>
        default:
            break;
        }
    }
    return true;
}
// Checkbox / radio callbacks
// - Creating a callback function is optional, but doing so enables you to
//   detect changes in the state of the elements.
bool CbCheckbox(void *pvGui, void *pvElemRef, int16_t nSelId, bool bState)
{
    gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
    gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
    gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
    if (pElemRef == NULL)
    {
        return false;
    }

    boolean bChecked = gslc_ElemXCheckboxGetState(pGui, pElemRef);

    // Determine which element issued the callback
    switch (pElem->nId)
    {
        //<Checkbox Enums !Start!>

        //<Checkbox Enums !End!>
    default:
        break;
    } // switch

    return true;
}
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
bool CbListbox(void *pvGui, void *pvElemRef, int16_t nSelId)
{
    gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
    gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
    gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
    char acTxt[MAX_STR + 1];

    if (pElemRef == NULL)
    {
        return false;
    }

    // From the element's ID we can determine which listbox was active.
    switch (pElem->nId)
    {
        //<Listbox Enums !Start!>
    case E_ELEM_LISTBOX1:
        if (nSelId != XLISTBOX_SEL_NONE)
        {
            gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
        }
        break;

        //<Listbox Enums !End!>
    default:
        break;
    }
    return true;
}
//<Draw Callback !Start!>
//<Draw Callback !End!>

// // Callback function for when a slider's position has been updated
// bool CbSlidePos(void *pvGui, void *pvElemRef, int16_t nPos)
// {
//     gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
//     gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
//     gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);
//     int16_t nVal;

//     // From the element's ID we can determine which slider was updated.
//     switch (pElem->nId)
//     {
//         //<Slider Enums !Start!>
//     case E_LISTSCROLL1:
//         // Fetch the slider position
//         nVal = gslc_ElemXSliderGetPos(pGui, m_pListSlider1);
//         break;

//         //<Slider Enums !End!>
//     default:
//         break;
//     }

//     return true;
// }
//<Tick Callback !Start!>
//<Tick Callback !End!>

bool isDeleted = false;
// -----------------------------------
// Main event loop
// -----------------------------------
