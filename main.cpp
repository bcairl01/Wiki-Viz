#define WEBTOOLS_VERBOSE_L3
#include <WebTools/WebTools.hpp>
#include <cmath>

extern "C" 
{
#include <UbigraphAPI.h>
}

size_t time_t_run;
size_t edge_counter = 0;
using namespace WebTools;


int main(int argc, char** argv)
{
	//std::cout << "Time to run : ";
	//std::cin  >> time_t_run;

	WebTools::Page::page::map map_out;
	WebTools::GraphLite::graph graph_test;

	

	//graph_test.get_vertex(0).set_position(1,1,1);
	//graph_test.get_vertex(1).set_position(-1,-1,-1);

	WebTools::GraphLite::set_client(graph_test);
	WebTools::GraphLite::run_host(argc,argv);


	//WebTools::Crawler::crawler_base 	crawler("Data",time_t_run,"http://www.wikipedia.org/");
	
	//crawler.add_inclusion("en.wikipedia.org/wiki");
	/*
	crawler.add_exclusion(".png");
	crawler.add_exclusion(".pdf");
	crawler.add_exclusion(".jpeg");
	crawler.add_exclusion(".bmp");
	crawler.add_exclusion("&");
	crawler.add_exclusion("/cim");
	*/
	
	//crawler.begin();
	//crawler.end();
	std::cout << "N to Load : ";
	std::cin  >> time_t_run;
	
	//WebTools::Page::build(crawler.get_pages(),map_out);

	/*
	ubigraph_clear();


	for( Page::page::map::iterator x_itr = map_out.begin(); x_itr != map_out.end(); ++x_itr)
	{

		ubigraph_new_vertex_w_id(x_itr->second.get_id());
		ubigraph_set_vertex_attribute(x_itr->second.get_id(),"shape","dodecahedron");
		ubigraph_set_vertex_attribute(x_itr->second.get_id(),"size","0.5");
		ubigraph_set_vertex_attribute(x_itr->second.get_id(),"color","#F00F00");
	}

	char buf[80UL];
	float fcomp = 0;
	for( Page::page::map::iterator x_itr = map_out.begin(); x_itr != map_out.end(); ++x_itr)
	{
		for( Types::c_hyperlink_citr y_itr = x_itr->second.get_hyperlinks().cbegin(); y_itr != x_itr->second.get_hyperlinks().cend(); ++y_itr)
		{
			Page::page::map::iterator linked_to = map_out.find(*y_itr);
			if(linked_to!=map_out.end() && (x_itr->second.get_id()!=linked_to->second.get_id()) )
			{
				fcomp = 
				WebTools::Utils::Hyperlinks::fcompare( 
					linked_to->second.get_address(), 
					x_itr->second.get_address() 
				);
				fcomp=powf(fcomp/0.5f,2.0f);
				if(fcomp>1.0f) fcomp = 1.0f;

				sprintf(buf,"%f",fcomp/2.0f);

				ubigraph_new_edge_w_id(edge_counter,x_itr->second.get_id(), linked_to->second.get_id());
				ubigraph_set_edge_attribute(edge_counter,"strength",buf);
				ubigraph_set_edge_attribute(edge_counter,"width",buf);
				ubigraph_set_edge_attribute(edge_counter,"showstrain","true");
				++edge_counter;
			}
		}
	}

	std::cin>>time_t_run;
	ubigraph_clear();
	*/


	WebTools::Page::build(WebTools::Page::loader("Data",time_t_run).get_pages(),map_out);
	WebTools::Page::enumerate(map_out);
	for( Page::page::map::iterator x_itr = map_out.begin(); x_itr != map_out.end(); ++x_itr)
	{
		graph_test.new_vertex(x_itr->second.get_id());
		graph_test.get_vertex(x_itr->second.get_id()).set_color(WebTools::GraphLite::Spec::color(1,0,1,.9));
	}

	for( Page::page::map::iterator x_itr = map_out.begin(); x_itr != map_out.end(); ++x_itr)
	{
		for( Types::c_hyperlink_citr y_itr = x_itr->second.get_hyperlinks().cbegin(); y_itr != x_itr->second.get_hyperlinks().cend(); ++y_itr)
		{
			Page::page::map::iterator linked_to = map_out.find(*y_itr);
			if(linked_to!=map_out.end() && (x_itr->second.get_id()!=linked_to->second.get_id()) )
			{
				graph_test.new_edge(x_itr->second.get_id(), linked_to->second.get_id());
				
				graph_test.get_last_edge().set_attraction(
					WebTools::Utils::Hyperlinks::fcompare( 
						linked_to->second.get_address(), 
						x_itr->second.get_address() 
					)
				);
			}
		}
	}
	while(1);
}
