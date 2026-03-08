#include "UsersController.h"
#include <drogon/orm/Mapper.h>
#include "models/Users.h"

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::test;


void UsersController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto db = app().getDbClient("pg");
    Mapper<Users> mapper(db);

    mapper.findAll(
        [callback](std::vector<Users> users)
        {
            Json::Value result(Json::arrayValue);

            for (const auto& u : users)
                result.append(u.toJson());

            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        },
        [callback](const DrogonDbException& e)
        {
            Json::Value err;
            err["error"] = e.base().what();
            callback(HttpResponse::newHttpJsonResponse(err));
        });
}
