#pragma once
#include <crails/cms/controllers/admin/blog.hpp>
#include <crails/i18n.hpp>
#include "app/controllers/admin/application.hpp"
#include "../../models/podcast_traits.hpp"

class AdminPodcastController : public Crails::Cms::AdminBlogController<PodcastTraits, AdminApplicationController>
{
  typedef Crails::Cms::AdminBlogController<PodcastTraits, AdminApplicationController> Super;
public:
  AdminPodcastController(Crails::Context& context) : Super(context)
  {
    vars["local_route"] = std::string(Super::scope) + "/podcast";
    vars["page_title"] = i18n::t("admin.menu.podcasts");
    vars["page_subtitle"] = i18n::t("admin.podcast-subtitle");
  }

  std::string get_view_scope() const override { return "podcast"; }
};
