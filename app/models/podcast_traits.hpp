#pragma once
#include "app/models/traits.hpp"
#include "podcast_index_query.hpp"
#include "podcast_tag_query.hpp"

struct PodcastTraits : public ApplicationTraits
{
  typedef Podcast Model;
  typedef Podcast PostModel;
  typedef PodcastIndexQuery IndexModel;
  typedef PodcastTagQuery TagModel;
};
