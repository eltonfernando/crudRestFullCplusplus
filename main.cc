#include <drogon/drogon.h>
int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 5555);
    LOG_INFO << "Server is listening on 0.0.0.0:5555";
    //Load config file
    //drogon::app().loadConfigFile("./config.yaml");
    drogon::app().loadConfigFile("../config.yaml");

        //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    LOG_INFO << "Server is shutting down";
    return 0;
}
