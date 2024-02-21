#pragma once
#include <string>
#include "podcast.hpp"

#pragma db view object(Podcast)
struct PodcastIndexQuery
{
  std::string get_database_name() const { return Podcast().get_database_name(); }
  Crails::Odb::id_type     id;
  bool                     published;
  std::string              tag_list;
  std::string              description;
  std::string              thumbnail;
  std::string              slug;

  Podcast to_post() const
  {
    Podcast post;

    post.set_id(id);
    post.set_published(published);
    post.set_tags(Crails::Cms::TagList(tag_list).to_vector());
    post.set_description(description);
    post.set_thumbnail_url(thumbnail);
    post.set_slug(slug);
    return post;
  }

  operator Podcast() const
  {
    return to_post();
  }
};
