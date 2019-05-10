#include "Dog.h"
#include "UI.h"

#include <crtdbg.h>
using namespace std;

int main()
{
	{
		Repository repo{};

		Dog d1{ "Bichon","Lisa",2,"https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese" };
		Dog d2{ "Labrador","Chira",1,"https://suntfericita.manager.ro/dbimg/images/LKBCD00Z.jpg" };
		Dog d3{ "Golden","Siba",4,"https://www.toateanimalele.ro/wp-content/uploads/2018/12/caini-terapie-autism-768x512.jpg" };
		Dog d4{ "Pudel","Bella",5,"https://www.toateanimalele.ro/wp-content/uploads/2019/03/numecainirecomandari-768x512.jpeg" };
		Dog d5{ "Labrador","Ema",2,"https://www.toateanimalele.ro/wp-content/uploads/2017/01/nume-de-caini-tofu.jpg" };
		Dog d6{ "Ciobanesc german","Otis",7,"https://business.facebook.com/frunzelacaini/photos/a.982457515195810/982457901862438/" };
		Dog d7{ "Beagle","Max",6,"https://www.rfi.ro/stiinta-82252-foto-caini-mutanti-obtinuti-de-savantii-chinezi-cum-arata-cateii" };
		Dog d8{ "Chiuhuahua","Daisy",4,"https://adevarul.ro/life-style/stil-de-viata/rase-caini-iubesc-copiii-1_5506b6d7448e03c0fd9" };
		Dog d9{ "Bulldog","Rex",8,"https://www.animalzoo.ro/cele-mai-scumpe-rase-de-caini-din-lume-doar-cei-bogati-si-le-permit" };
		Dog d10{ "Teckel","Nero",5,"https://animax.ro/11-beneficii-ale-hranei-cu-probiotice-pentru-caini.html" };

		repo.add(d1);
		repo.add(d2);
		repo.add(d3);
		repo.add(d4);
		repo.add(d5);
		repo.add(d6);
		repo.add(d7);
		repo.add(d8);
		repo.add(d9);
		repo.add(d10);

		Controller ctrl{ repo };
		UI ui{ ctrl };
		ui.run();
	}
	_CrtDumpMemoryLeaks;
	return 0;
}