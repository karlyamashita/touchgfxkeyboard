#ifndef SCREENSETTINGSVIEW_HPP
#define SCREENSETTINGSVIEW_HPP

#include <gui_generated/screensettings_screen/ScreenSettingsViewBase.hpp>
#include <gui/screensettings_screen/ScreenSettingsPresenter.hpp>

class ScreenSettingsView : public ScreenSettingsViewBase
{
public:
    ScreenSettingsView();
    virtual ~ScreenSettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void keyboardSelected(uint8_t value);
    virtual void updateScreen();
protected:
};

#endif // SCREENSETTINGSVIEW_HPP
