#include <juce_gui_extra/juce_gui_extra.h>
#include "MainComponent.h"

class EncounterLauncher : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override       { return "EncounterLauncher"; }
    const juce::String getApplicationVersion() override    { return "1.0"; }
    void initialise(const juce::String&) override          { mainWindow.reset(new MainWindow()); }
    void shutdown() override                               { mainWindow = nullptr; }

private:
    class MainWindow : public juce::DocumentWindow
    {
    public:
        MainWindow() : DocumentWindow("EncounterLauncher",
                                      juce::Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId),
                                      DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(new MainComponent(), true);
            setResizable(true, false);
            setCentrePosition(600, 400);
            setVisible(true);
        }

        void closeButtonPressed() override { juce::JUCEApplication::getInstance()->systemRequestedQuit(); }
    };

    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION(EncounterLauncher)
