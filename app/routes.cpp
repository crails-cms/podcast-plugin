#include <crails/router.hpp>
#include <crails/cms/routes.hpp>
#include <crails/cms/views/admin_menu.hpp>
#include "lib/plugin-odb.hxx"
#include "app/controllers/podcast.hpp"
#include "app/controllers/admin/podcast.hpp"

void initialize_plugin_routes()
{
  auto& router = Crails::Router::singleton::require();
  auto& cms_routes = Crails::Cms::Routes::singleton::require();
  auto& admin_menu = Crails::Cms::AdminMenu::singleton::require();

  router.scope(PodcastController::scope, [&]()
  {
    cms_routes.set_path_for<PodcastController>(router);
    router.match_action("GET", "/",      PodcastController, index);
    router.match_action("GET", "/:slug", PodcastController, show);
  });

  router.scope(AdminApplicationController::scope, [&]()
  {
    router.scope(PodcastController::scope, [&]()
    {
      admin_menu.add({3, "podcasts", router.get_current_scope()});
      cms_routes.set_path_for<AdminPodcastController>(router);
      router.match_action("PUT",  "/preview", PodcastController, preview);
      router.match_action("POST", "/preview", PodcastController, preview);
      router.libcrails_cms_admin_crud("/", AdminPodcastController);
    });
  });
}
