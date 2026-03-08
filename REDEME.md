


# criando um novo app
./build/drogon_ctl/drogon_ctl create project app

./build/drogon_ctl/drogon_ctl create controller User

./build/drogon_ctl/drogon_ctl create controller -r UserApi

./build/drogon_ctl/drogon_ctl create filter AuthFilter


./build/drogon_ctl/drogon_ctl create plugin JwtPlugin

# fluxo 

psql -h localhost -p 9432 -U admin -d test -f db/migrations/001_create_users.sql
drogon_ctl create model pg models users
drogon_ctl create controller UsersController

curl http://localhost:5555/users