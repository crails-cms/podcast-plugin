#pragma once
#include <string>
#include "podcast.hpp"

#pragma db view query("SELECT value, count(value) FROM \"podcast_Podcast_tags\" WHERE (?) GROUP BY value")
struct PodcastTagQuery
{
  std::string get_database_name() const { return Podcast().get_database_name(); }
  #pragma db type("VARCHAR")
  std::string value;
  #pragma db type("INTEGER")
  size_t count;
};
