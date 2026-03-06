#include "ox/oxygine.hpp"
#include "ox/Stage.hpp"
#include "ox/DebugActor.hpp"
#include "MainScene.h"

using namespace oxygine;

namespace
{
    spMainScene g_mainScene;

    int mainloop()
    {
        bool done = core::update();

        getStage()->update();

        if(core::beginRendering())
        {
            Color clearColor(32,32,32,255);
            Rect viewport(Point(0,0), core::getDisplaySize());
            getStage()->render(clearColor, viewport);
            core::swapDisplayBuffers();
        }

        return done ? 1 : 0;
    }

    void run()
    {
        ObjectBase::__startTracingLeaks();

        core::init_desc desc;
        desc.title = "Mini Tower Defense";
        desc.w = 960;
        desc.h = 640;

        core::init(&desc);

        Stage::instance = new Stage();
        getStage()->setSize(core::getDisplaySize());

        DebugActor::show();

        g_mainScene = new MainScene();
        getStage()->addChild(g_mainScene);

        while (true)
        {
            if (mainloop())
                break;
        }

        g_mainScene = nullptr;

        core::release();
        ObjectBase::dumpCreatedObjects();
        ObjectBase::__stopTracingLeaks();
    }

}

#ifdef OXYGINE_SDL
#include "SDL_main.h"
#include "SDL.h"

extern "C"
{
    int main(int argc, char* argv[])
    {
        run();
        return 0;
    }
}
#endif