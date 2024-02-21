#include "podcast.hpp"
#include <crails/cms/models/attachment_url.hpp>
#include <crails/logger.hpp>
#include <filesystem>
#include "lib/plugin-odb.hxx"
#include "app/models/attachment.hpp"

odb_instantiable_impl(Podcast)

using namespace Crails;
using namespace std;

const std::string Podcast::scope = "podcast";
const std::string Podcast::plural_scope = "podcasts";
const std::string Podcast::view = "podcast/show";

void Podcast::edit(Data params)
{
  Cms::BlogPost::edit(params);
  if (params["audio_id"].exists())
    set_audio_from_id(params["audio_id"].as<Odb::id_type>());
  else if (params["audio_url"].exists())
    set_audio_url(params["audio_url"]);
}

void Podcast::set_audio_from_id(Odb::id_type id)
{
  Odb::ConnectionHandle().find_one(audio, id);
}

void Podcast::set_audio_from_url(const string& url)
{
  set_attachment_from_url(audio, url);
}

std::string Podcast::get_audio_url() const
{
  if (audio)
    return audio->as_attachment().get_url();
  return std::string();
}
