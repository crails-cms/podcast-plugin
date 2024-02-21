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
    cms_routes.register_blog_routes<PodcastController>(router);
  });

  router.scope(AdminApplicationController::scope, [&]()
  {
    router.scope(PodcastController::scope, [&]()
    {
      admin_menu.add({4, "podcasts", router.get_current_scope()});
      cms_routes.register_blog_admin_routes<PodcastController, AdminPodcastController>(router);
    });
  });
}
