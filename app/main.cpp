#include <string>

void initialize_plugin_routes();
void initialize_plugin_renderers();
void install_plugin_database();
void uninstall_plugin_database();

extern unsigned char podcast_plugin_application_js[];
extern unsigned int  podcast_plugin_application_js_len;
extern unsigned char podcast_plugin_application_css[];
extern unsigned int  podcast_plugin_application_css_len;

extern "C"
{
  void initialize()
  {
    initialize_plugin_routes();
    initialize_plugin_renderers();
  }

  void install()
  {
    install_plugin_database();
  }

  void uninstall()
  {
    uninstall_plugin_database();
  }

  std::string_view plugin_javascript()
  {
    return std::string_view(
      reinterpret_cast<const char*>(podcast_plugin_application_js),
      podcast_plugin_application_js_len
    );
  }

  std::string_view plugin_stylesheet()
  {
    return std::string_view(
      reinterpret_cast<const char*>(podcast_plugin_application_css),
      podcast_plugin_application_css_len
    );
  }
}
