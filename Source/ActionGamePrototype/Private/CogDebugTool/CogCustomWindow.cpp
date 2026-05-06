#include "CogDebugTool/CogCustomWindow.h"

#if ENABLE_COG

#include "GameFramework/Actor.h"
#include "CogImguiHelper.h"

void CogCustomWindow::Initialize()
{
	Super::Initialize();
}

void CogCustomWindow::RenderHelp()
{
	ImGui::Text("Testing debug windows!");
}

void CogCustomWindow::RenderContent()
{
	Super::RenderContent();
	
	ImGui::Text("Exotic numbers here :)");
}

#endif //ENABLE_COG