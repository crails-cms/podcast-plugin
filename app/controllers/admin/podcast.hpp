#pragma once
#include <crails/cms/controllers/admin/blog.hpp>
#include "app/controllers/admin/application.hpp"
#include "../../models/podcast_traits.hpp"

class AdminPodcastController : public Crails::Cms::AdminBlogController<PodcastTraits, AdminApplicationController>
{
  typedef Crails::Cms::AdminBlogController<PodcastTraits, AdminApplicationController> Super;
public:
  AdminPodcastController(Crails::Context& context) : Super(context)
  {
  }

  std::string get_view_scope() const override { return "podcast"; }
};
