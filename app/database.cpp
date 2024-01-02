#include <crails/odb/connection.hpp>

const char* drop_podcast_tags_query = "DROP TABLE IF EXISTS \"podcast_Podcast_tags\" CASCADE;";
const char* drop_podcast_query = "DROP TABLE IF EXISTS \"podcast_Podcast\" CASCADE;";
const char* create_podcast_query =
  "CREATE TABLE \"podcast_Podcast\" ("
    "\"id\" BIGSERIAL NOT NULL PRIMARY KEY,"
    "\"deleted\" BOOLEAN NOT NULL DEFAULT FALSE,"
    "\"created_at\" BIGINT NULL,"
    "\"updated_at\" BIGINT NULL,"
    "\"title\" TEXT NOT NULL,"
    "\"slug\" TEXT NOT NULL,"
    "\"body\" TEXT NOT NULL,"
    "\"description\" TEXT NOT NULL,"
    "\"thumbnail\" TEXT NOT NULL,"
    "\"preview\" BOOLEAN NOT NULL,"
    "\"tag_list\" TEXT NOT NULL,"
    "\"published\" BOOLEAN NOT NULL,"
    "\"publication_at\" BIGINT NOT NULL,"
    "\"author_id\" BIGINT NOT NULL,"
    "\"audio\" BIGINT NULL);";
const char* create_podcast_tags_query =
  "CREATE TABLE \"podcast_Podcast_tags\" ("
    "\"object_id\" BIGINT NOT NULL,"
    "\"index\" BIGINT NOT NULL,"
    "\"value\" TEXT NOT NULL,"
    "CONSTRAINT \"object_id_fk\""
    "  FOREIGN KEY (\"object_id\")"
    "  REFERENCES \"podcast_Podcast\" (\"id\")"
    "  ON DELETE CASCADE);";
const char* create_tag_index_query_a =
  "CREATE INDEX \"podcast_Podcast_tags_object_id_i\""
  " ON \"podcast_Podcast_tags\" (\"object_id\");";
const char* create_tag_index_query_b =
  "CREATE INDEX \"podcast_Podcast_tags_index_i\""
  " ON \"podcast_Podcast_tags\" (\"index\");";
const char* constraint_attachment_query =
  "ALTER TABLE \"podcast_Podcast\""
  "  ADD CONSTRAINT \"audio_fk\""
  "  FOREIGN KEY (\"audio\")"
  "  REFERENCES \"podcast_Attachment\" (\"id\")"
  "  INITIALLY DEFERRED;";

void install_plugin_database()
{
  Crails::Odb::Connection database;

  database.transaction.require("odb");
  database.transaction.get_database().execute(create_podcast_query);
  database.transaction.get_database().execute(create_podcast_tags_query);
  database.transaction.get_database().execute(create_tag_index_query_a);
  database.transaction.get_database().execute(create_tag_index_query_b);
  database.transaction.get_database().execute(constraint_attachment_query);
  database.commit();
}

void uninstall_plugin_database()
{
  Crails::Odb::Connection database;

  database.transaction.require("odb");
  database.transaction.get_database().execute(drop_podcast_tags_query);
  database.transaction.get_database().execute(drop_podcast_query);
  database.commit();
}
