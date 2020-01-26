#include <iostream>
#include <string>
#include <sstream>

#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>

#include <cppcms/json.h>

class hello : public cppcms::application
{  
public:  
    hello(cppcms::service &service) : cppcms::application(service)  
    {
        
    }

    virtual void main(std::string url);  
};

void hello::main(std::string /*url*/)  
{
    
    
    cppcms::json::value json;
    json["fuck"] = "hell";
    json["crazy"] = "mad";
    json["shit"] = 5;
    json.save(std::cout, cppcms::json::compact | cppcms::json::readable);
    std::stringstream tmp;
    tmp << json;
    this->response().add_header("Content-Type", "application/json");
    this->response().out() << tmp.str();
}

int main(int argc, char** argv)
{
    try
    {  
        cppcms::service service(argc,argv);
        service.applications_pool().mount(
            cppcms::applications_factory<hello>()
        );
        service.run();
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}