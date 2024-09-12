#include <exception>

class GuiException : std::exception
{
};

class WidgetException : GuiException
{
    const char* what() const noexcept override;
};

const char* WidgetException::what() const noexcept
{
    return "Widget Exception";
}