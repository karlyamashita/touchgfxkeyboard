#ifndef SCREENSETTINGSPRESENTER_HPP
#define SCREENSETTINGSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenSettingsView;

class ScreenSettingsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenSettingsPresenter(ScreenSettingsView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ScreenSettingsPresenter() {};

private:
    ScreenSettingsPresenter();

    ScreenSettingsView& view;
};

#endif // SCREENSETTINGSPRESENTER_HPP
