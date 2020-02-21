#include <gui/screensettings_screen/ScreenSettingsView.hpp>
//#include "PollingRoutines.h"// add
//#include "RingBuff.h"// add

Unicode::UnicodeChar keyboardBuffer[2][18]; // add
uint8_t keyboardSelection = 0; // add

ScreenSettingsView::ScreenSettingsView()
{

}

void ScreenSettingsView::setupScreen()
{
    ScreenSettingsViewBase::setupScreen();
}

void ScreenSettingsView::tearDownScreen()
{
    ScreenSettingsViewBase::tearDownScreen();
}

void ScreenSettingsView::keyboardSelected(uint8_t value)
{
	keyboardSelection = value;
}

void ScreenSettingsView::updateScreen()
{
	if(Unicode::strlen(keyboardBuffer[0]) > 0)
	{
		memset(&textAreaSsidBuffer, 0, TEXTAREASSID_SIZE);
		Unicode::strncpy(textAreaSsidBuffer, keyboardBuffer[0], TEXTAREASSID_SIZE - 1);
		textAreaSsidBuffer[TEXTAREASSID_SIZE-1] = '\0'; // make sure last index is null
		textAreaSsid.invalidate();
	}
	if(Unicode::strlen(keyboardBuffer[1]) > 0)
	{
		char temp[18] = {0};
		uint8_t n = Unicode::strlen(keyboardBuffer[1]);
		Unicode::UnicodeChar unicodeBuf[18] = {0};

		memset(&temp, '*', n);

		Unicode::fromUTF8((uint8_t*)temp, unicodeBuf, Unicode::strlen(keyboardBuffer[1]));

		memset(&textAreaPwBuffer, 0, TEXTAREAPW_SIZE);
		Unicode::strncpy(textAreaPwBuffer, unicodeBuf, TEXTAREAPW_SIZE - 1);
		textAreaPwBuffer[TEXTAREAPW_SIZE-1] = '\0'; // make sure last index is null
		textAreaPw.invalidate();
	}
}
