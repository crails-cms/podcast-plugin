#pragma once
#include <crails/cms/models/blog/post.hpp>
#include "app/models/attachment.hpp"

#pragma db object table("podcast_Podcast")
class Podcast : public Crails::Cms::BlogPost
{
  odb_instantiable()
public:
  static const std::string scope;
  static const std::string plural_scope;
  static const std::string view;

  #pragma db view object(Podcast)
  struct Count
  {
    #pragma db column("count(" + Podcast::id + ")")
    size_t value;
  };

  void edit(Data) override;

  std::string get_audio_url() const;

private:
  void set_audio_from_id(Crails::Odb::id_type);
  void set_audio_from_url(const std::string&);
  std::shared_ptr<Attachment> audio;
};
