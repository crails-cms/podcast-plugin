#pragma once
#include <crails/cms/controllers/blog.hpp>
#include "app/controllers/application.hpp"
#include "../models/podcast_traits.hpp"

class PodcastController : public Crails::Cms::BlogController<PodcastTraits, ApplicationController>
{
  typedef Crails::Cms::BlogController<PodcastTraits, ApplicationController> Super;
public:
  static constexpr const char* scope = "podcast";

  PodcastController(Crails::Context& context) : Super(context)
  {
    vars["local_route"] = "/podcast";
  }

  std::string get_view_scope() const override { return "podcast"; }
};
