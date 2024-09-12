#pragma once
#include "Widget.h"
#include "Callback.hpp"

class Clickable : public Widget 
{
    public:
        template <typename F, typename... Args>
        void onPressed(F&& functor, Args&& ... args)
        {
            onPressedCallback = createCallback(std::forward<F>(functor), std::forward<Args>(args)...);
        }

        template <typename F, typename... Args>
        void onReleased(F&& functor, Args&& ... args)
        {
            onReleasedCallback = createCallback(std::forward<F>(functor), std::forward<Args>(args)...);
        }

        template <typename F, typename... Args>
        void onHover(F&& functor, Args&& ... args)
        {
            onHoverCallback = createCallback(std::forward<F>(functor), std::forward<Args>(args)...);
        }

        template <typename F, typename... Args>
        void onStopHover(F&& functor, Args&& ... args)
        {
            onStopHoverCallback = createCallback(std::forward<F>(functor), std::forward<Args>(args)...);
        }

    protected:
        std::unique_ptr<CallbackBase> onPressedCallback;
        std::unique_ptr<CallbackBase> onReleasedCallback;
        std::unique_ptr<CallbackBase> onHoverCallback;
        std::unique_ptr<CallbackBase> onStopHoverCallback;
};