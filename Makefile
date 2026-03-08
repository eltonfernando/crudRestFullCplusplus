
create_controller:
    drogon_ctl create controller BoundingBox -r
create_model:
    drogon_ctl create model database.db bounding_box

build:
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
    cmake ..
    make

run:
    ./bbox_api 

db_update:
    liquibase --defaultsFile=liquibase.properties update

db_rollback:
    liquibase --defaultsFile=liquibase.properties rollback

alias_cli:
    alias drogon_ctl='./build/_deps/drogon-build/drogon_ctl/drogon_ctl'