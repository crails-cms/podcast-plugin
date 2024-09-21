#pragma once
#include <crails/cms/sitemap_resource.hpp>
#include "app/models/blog_post_traits.hpp"
#include "controllers/podcast.hpp"
#include "lib/odb/application-odb.hxx"

typedef Crails::Cms::SiteMap::ResourceIndex<PodcastController, BlogPostTraits> PodcastSitemap;
