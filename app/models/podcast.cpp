#include "podcast.hpp"
#include "lib/plugin-odb.hxx"

odb_instantiable_impl(Podcast)

using namespace Crails;

const std::string Podcast::scope = "podcast";
const std::string Podcast::plural_scope = "podcasts";
const std::string Podcast::view = "podcast/show";

void Podcast::edit(Data params)
{
  Cms::BlogPost::edit(params);
  if (params["audio_id"].exists())
  {
    Odb::Connection database;

    database.rollback_on_destruction = false;
    database.find_one(audio, params["audio_id"].as<Odb::id_type>());
  }
}

std::string Podcast::get_audio_url() const
{
  if (audio)
    return audio->as_attachment().get_url();
  return std::string();
}
