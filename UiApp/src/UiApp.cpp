#include "UiEngine.h"
#include "UiTestScreen.h"

class UiApp : public UiEngine::Application
{
public:
    UiApp(UiEngine::WindowProps& props): Application(props)
    {
        std::cout << "Hello From App" << std::endl;
    }

    ~UiApp()
    {

    }

    void OnUpdate() override
    {
        uiTest.RenderTestUi();
    }

private:
    UiTestScreens uiTest;
    UiEngine::WindowProps m_props;
};

int main()
{
    UiEngine::WindowProps props;
    props.Title = "UiAnalysis";
    props.Width = 800;
    props.Height = 480;

    UiApp* ui = new UiApp(props);
    ui->Run();
    ui->OnUpdate();
    delete(ui);
}