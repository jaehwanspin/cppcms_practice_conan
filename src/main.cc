#include <iostream>

#include <boost/property_tree/json_parser.hpp>

#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  

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
    // boost::property_tree::ptree json_root;
    // boost::property_tree::path path;
    // boost::property_tree::ptree json_child;
    // json_child.put("msg", "hello");
    // json_root.add_child(path, json_child);

    // std::stringstream string_stream;
    // boost::property_tree::json_parser::write_json(string_stream, json_root);

    // this->response().out() << string_stream.str();
    this->response().add_header("Content-Type", "application/json");
    this->response().out() << "{\"msg\":\"hell\"}";
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