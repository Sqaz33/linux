#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    Display *display;
    Window window;
    XEvent event;
    int screen;
    
    // Открываем соединение с X сервером
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }
    
    // Получаем номер экрана по умолчанию
    screen = DefaultScreen(display);
    
    // Создаем окно
    window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        100, 100,        // x, y позиция
        400, 300,        // ширина, высота
        1,               // толщина границы
        BlackPixel(display, screen),  // цвет границы
        WhitePixel(display, screen)   // цвет фона
    );
    
    // Устанавливаем название окна
    XStoreName(display, window, "Мое X Window");
    
    // Указываем, какие события мы хотим обрабатывать
    XSelectInput(display, window, 
        ExposureMask |      // событие перерисовки
        KeyPressMask |      // нажатие клавиш
        ButtonPressMask |   // нажатие кнопок мыши
        StructureNotifyMask // события изменения размера/перемещения
    );
    
    // Показываем окно
    XMapWindow(display, window);
    
    // Обработчик для события Close (крестик)
    Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDeleteMessage, 1);
    
    // Обработка событий
    int running = 1;
    while (running) {
        XNextEvent(display, &event);
        
        switch (event.type) {
            case Expose:
                // Рисуем что-нибудь при перерисовке
                printf("Window exposed\n");
                break;
                
            case KeyPress:
                // Выход при нажатии любой клавиши
                printf("Key pressed, exiting...\n");
                running = 0;
                break;
                
            case ButtonPress:
                printf("Mouse button pressed at (%d, %d)\n", 
                    event.xbutton.x, event.xbutton.y);
                break;
                
            case ClientMessage:
                // Проверяем, не нажали ли на крестик
                if ((Atom)event.xclient.data.l[0] == wmDeleteMessage) {
                    printf("Close button clicked, exiting...\n");
                    running = 0;
                }
                break;
        }
    }
    
    // Закрываем окно и освобождаем ресурсы
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    
    return 0;
}