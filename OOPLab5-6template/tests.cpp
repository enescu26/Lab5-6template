#include "tests.h"
#include "Repository.h"
#include "Controller.h"
#include <assert.h>

void test_domain() {
	Dog d{ "Bichon","Lisa",2,"https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese.jpg?itok=4WdSkPJX" };
	Dog d1{ "Bichon","Lisa",2,"https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese.jpg?itok=4WdSkPJX" };
	assert(d1 == d);
	assert(d.getBreed() == "Bichon");
	assert(d.getName() == "Lisa");
	assert(d.getAge() == 2);
	assert(d.getPhotograph() == "https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese.jpg?itok=4WdSkPJX");

	d.setBreed("Husky");
	d.setName("Mia");
	d.setAge(6);
	d.setPhotograph("https://www.click.ro");
	assert(d.getBreed() == "Husky");
	assert(d.getName() == "Mia");
	assert(d.getPhotograph() == "https://www.click.ro");
}
void test_repo() {
	Repository repo;
	Controller ctrl = Controller(repo);

	assert(ctrl.getSize() == 0);
	Dog d{ "Bichon","Lisa",2,"https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese.jpg?itok=4WdSkPJX" };
	ctrl.add(d);
	assert(ctrl.getSize() == 1);
	Dog d2{ "Labrador","Chira",1,"https://suntfericita.manager.ro/dbimg/images/LKBCD00Z.jpg" };
	assert(ctrl.getSize() == 2);
	ctrl.remove("Bichon", "Lisa");
	assert(ctrl.getSize() == 1);
	ctrl.update("Labrador", "Chira", "Husky", "Bella", 5, "https://www.youtube.com/watch?v=p1muCWIktbY");
	assert(ctrl.getIndex(1).getAge() == 2);

}