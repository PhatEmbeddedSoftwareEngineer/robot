#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
/**
 * 3 cap do cua toc do de dieu khien robot 
*/
enum speedSettings
{
  STOP,
  SLOW = 50,
  NORMAL = 80,
  FAST = 120,
  MOVE_LEFT=70,
  MOVE_RIGHT=70,
  BACK_LEFT=70,
  BACK_RIGHT=70
};

class socket
{
private:
    int baud=115200;
    speedSettings currentSpeedSettings;
    const char *ssid = "Galaxy";
    const char *password = "12345678";
    
public:
    socket();
    void setMotorSpeed();
    void setCurrentSpeed(speedSettings newSpeedSettings);
    
    speedSettings getCurrentSpeed()
    {
        return currentSpeedSettings;
    }
    void turnLeft();
    void turnRight();
    void moveForward();
    void moveBackward();
    void TienTrai(speedSettings value);
    void TienPhai(speedSettings value);
    void LuiTrai(speedSettings value);
    void LuiPhai(speedSettings value);
    void stop();
    void connectWifi();
    void sendCarCommand(const char *command);
    void readyCar();
    static String indexPageProcessor(const String &var);

    static void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, 
                        AwsEventType type, void *arg, uint8_t *data, size_t len);

    static void notFound(AsyncWebServerRequest *request);

    void initSPIFFS();

    void initWebsocket();
};

extern socket _soc;
