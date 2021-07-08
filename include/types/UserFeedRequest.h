#pragma once

#include <nlohmann/json.hpp>

#include <optional>
#include <stdexcept>
#include <regex>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace IgTypes {
    using nlohmann::json;

    class FacepileTopLiker {
        public:
        FacepileTopLiker() = default;
        virtual ~FacepileTopLiker() = default;

        private:
        std::shared_ptr<int64_t> pk;
        std::shared_ptr<std::string> username;
        std::shared_ptr<std::string> full_name;
        std::shared_ptr<bool> is_private;
        std::shared_ptr<std::string> profile_pic_url;
        std::shared_ptr<std::string> profile_pic_id;
        std::shared_ptr<bool> is_verified;
        std::shared_ptr<int64_t> follow_friction_type;

        public:
        std::shared_ptr<int64_t> get_pk() const { return pk; }
        void set_pk(std::shared_ptr<int64_t> value) { this->pk = value; }

        std::shared_ptr<std::string> get_username() const { return username; }
        void set_username(std::shared_ptr<std::string> value) { this->username = value; }

        std::shared_ptr<std::string> get_full_name() const { return full_name; }
        void set_full_name(std::shared_ptr<std::string> value) { this->full_name = value; }

        std::shared_ptr<bool> get_is_private() const { return is_private; }
        void set_is_private(std::shared_ptr<bool> value) { this->is_private = value; }

        std::shared_ptr<std::string> get_profile_pic_url() const { return profile_pic_url; }
        void set_profile_pic_url(std::shared_ptr<std::string> value) { this->profile_pic_url = value; }

        std::shared_ptr<std::string> get_profile_pic_id() const { return profile_pic_id; }
        void set_profile_pic_id(std::shared_ptr<std::string> value) { this->profile_pic_id = value; }

        std::shared_ptr<bool> get_is_verified() const { return is_verified; }
        void set_is_verified(std::shared_ptr<bool> value) { this->is_verified = value; }

        std::shared_ptr<int64_t> get_follow_friction_type() const { return follow_friction_type; }
        void set_follow_friction_type(std::shared_ptr<int64_t> value) { this->follow_friction_type = value; }
    };

    class Candidate {
        public:
        Candidate() = default;
        virtual ~Candidate() = default;

        private:
        std::shared_ptr<int64_t> width;
        std::shared_ptr<int64_t> height;
        std::shared_ptr<std::string> url;
        std::shared_ptr<std::string> scans_profile;
        std::shared_ptr<std::vector<int64_t>> estimated_scans_sizes;

        public:
        std::shared_ptr<int64_t> get_width() const { return width; }
        void set_width(std::shared_ptr<int64_t> value) { this->width = value; }

        std::shared_ptr<int64_t> get_height() const { return height; }
        void set_height(std::shared_ptr<int64_t> value) { this->height = value; }

        std::shared_ptr<std::string> get_url() const { return url; }
        void set_url(std::shared_ptr<std::string> value) { this->url = value; }

        std::shared_ptr<std::string> get_scans_profile() const { return scans_profile; }
        void set_scans_profile(std::shared_ptr<std::string> value) { this->scans_profile = value; }

        std::shared_ptr<std::vector<int64_t>> get_estimated_scans_sizes() const { return estimated_scans_sizes; }
        void set_estimated_scans_sizes(std::shared_ptr<std::vector<int64_t>> value) { this->estimated_scans_sizes = value; }
    };

    class ImageVersions2 {
        public:
        ImageVersions2() = default;
        virtual ~ImageVersions2() = default;

        private:
        std::shared_ptr<std::vector<Candidate>> candidates;

        public:
        std::shared_ptr<std::vector<Candidate>> get_candidates() const { return candidates; }
        void set_candidates(std::shared_ptr<std::vector<Candidate>> value) { this->candidates = value; }
    };

    class LikerConfig {
        public:
        LikerConfig() = default;
        virtual ~LikerConfig() = default;

        private:
        std::shared_ptr<bool> is_daisy;
        std::shared_ptr<bool> hide_view_count;
        std::shared_ptr<bool> show_count_in_likers_list;
        std::shared_ptr<bool> show_view_count_in_likers_list;
        std::shared_ptr<bool> show_daisy_liker_list_header;
        std::shared_ptr<bool> show_learn_more;
        std::shared_ptr<int64_t> ads_display_mode;
        std::shared_ptr<int64_t> display_mode;
        std::shared_ptr<bool> disable_liker_list_navigation;
        std::shared_ptr<bool> show_author_view_likes_button;
        std::shared_ptr<bool> is_in_daisy_controls;

        public:
        std::shared_ptr<bool> get_is_daisy() const { return is_daisy; }
        void set_is_daisy(std::shared_ptr<bool> value) { this->is_daisy = value; }

        std::shared_ptr<bool> get_hide_view_count() const { return hide_view_count; }
        void set_hide_view_count(std::shared_ptr<bool> value) { this->hide_view_count = value; }

        std::shared_ptr<bool> get_show_count_in_likers_list() const { return show_count_in_likers_list; }
        void set_show_count_in_likers_list(std::shared_ptr<bool> value) { this->show_count_in_likers_list = value; }

        std::shared_ptr<bool> get_show_view_count_in_likers_list() const { return show_view_count_in_likers_list; }
        void set_show_view_count_in_likers_list(std::shared_ptr<bool> value) { this->show_view_count_in_likers_list = value; }

        std::shared_ptr<bool> get_show_daisy_liker_list_header() const { return show_daisy_liker_list_header; }
        void set_show_daisy_liker_list_header(std::shared_ptr<bool> value) { this->show_daisy_liker_list_header = value; }

        std::shared_ptr<bool> get_show_learn_more() const { return show_learn_more; }
        void set_show_learn_more(std::shared_ptr<bool> value) { this->show_learn_more = value; }

        std::shared_ptr<int64_t> get_ads_display_mode() const { return ads_display_mode; }
        void set_ads_display_mode(std::shared_ptr<int64_t> value) { this->ads_display_mode = value; }

        std::shared_ptr<int64_t> get_display_mode() const { return display_mode; }
        void set_display_mode(std::shared_ptr<int64_t> value) { this->display_mode = value; }

        std::shared_ptr<bool> get_disable_liker_list_navigation() const { return disable_liker_list_navigation; }
        void set_disable_liker_list_navigation(std::shared_ptr<bool> value) { this->disable_liker_list_navigation = value; }

        std::shared_ptr<bool> get_show_author_view_likes_button() const { return show_author_view_likes_button; }
        void set_show_author_view_likes_button(std::shared_ptr<bool> value) { this->show_author_view_likes_button = value; }

        std::shared_ptr<bool> get_is_in_daisy_controls() const { return is_in_daisy_controls; }
        void set_is_in_daisy_controls(std::shared_ptr<bool> value) { this->is_in_daisy_controls = value; }
    };

    class SharingFrictionInfo {
        public:
        SharingFrictionInfo() = default;
        virtual ~SharingFrictionInfo() = default;

        private:
        std::shared_ptr<bool> should_have_sharing_friction;
        nlohmann::json bloks_app_url;

        public:
        std::shared_ptr<bool> get_should_have_sharing_friction() const { return should_have_sharing_friction; }
        void set_should_have_sharing_friction(std::shared_ptr<bool> value) { this->should_have_sharing_friction = value; }

        const nlohmann::json & get_bloks_app_url() const { return bloks_app_url; }
        nlohmann::json & get_mutable_bloks_app_url() { return bloks_app_url; }
        void set_bloks_app_url(const nlohmann::json & value) { this->bloks_app_url = value; }
    };

    class UserFeed {
        public:
        UserFeed() = default;
        virtual ~UserFeed() = default;

        private:
        std::shared_ptr<int64_t> pk;
        std::shared_ptr<std::string> username;
        std::shared_ptr<std::string> full_name;
        std::shared_ptr<bool> is_private;
        std::shared_ptr<std::string> profile_pic_url;
        std::shared_ptr<bool> is_verified;
        std::shared_ptr<int64_t> follow_friction_type;
        std::shared_ptr<bool> has_anonymous_profile_picture;
        std::shared_ptr<bool> is_unpublished;
        std::shared_ptr<bool> is_favorite;
        std::shared_ptr<std::vector<nlohmann::json>> account_badges;
        std::shared_ptr<int64_t> latest_reel_media;

        public:
        std::shared_ptr<int64_t> get_pk() const { return pk; }
        void set_pk(std::shared_ptr<int64_t> value) { this->pk = value; }

        std::shared_ptr<std::string> get_username() const { return username; }
        void set_username(std::shared_ptr<std::string> value) { this->username = value; }

        std::shared_ptr<std::string> get_full_name() const { return full_name; }
        void set_full_name(std::shared_ptr<std::string> value) { this->full_name = value; }

        std::shared_ptr<bool> get_is_private() const { return is_private; }
        void set_is_private(std::shared_ptr<bool> value) { this->is_private = value; }

        std::shared_ptr<std::string> get_profile_pic_url() const { return profile_pic_url; }
        void set_profile_pic_url(std::shared_ptr<std::string> value) { this->profile_pic_url = value; }

        std::shared_ptr<bool> get_is_verified() const { return is_verified; }
        void set_is_verified(std::shared_ptr<bool> value) { this->is_verified = value; }

        std::shared_ptr<int64_t> get_follow_friction_type() const { return follow_friction_type; }
        void set_follow_friction_type(std::shared_ptr<int64_t> value) { this->follow_friction_type = value; }

        std::shared_ptr<bool> get_has_anonymous_profile_picture() const { return has_anonymous_profile_picture; }
        void set_has_anonymous_profile_picture(std::shared_ptr<bool> value) { this->has_anonymous_profile_picture = value; }

        std::shared_ptr<bool> get_is_unpublished() const { return is_unpublished; }
        void set_is_unpublished(std::shared_ptr<bool> value) { this->is_unpublished = value; }

        std::shared_ptr<bool> get_is_favorite() const { return is_favorite; }
        void set_is_favorite(std::shared_ptr<bool> value) { this->is_favorite = value; }

        std::shared_ptr<std::vector<nlohmann::json>> get_account_badges() const { return account_badges; }
        void set_account_badges(std::shared_ptr<std::vector<nlohmann::json>> value) { this->account_badges = value; }

        std::shared_ptr<int64_t> get_latest_reel_media() const { return latest_reel_media; }
        void set_latest_reel_media(std::shared_ptr<int64_t> value) { this->latest_reel_media = value; }
    };

    class Item {
        public:
        Item() = default;
        virtual ~Item() = default;

        private:
        std::shared_ptr<int64_t> taken_at;
        std::shared_ptr<double> pk;
        std::shared_ptr<std::string> id;
        std::shared_ptr<int64_t> device_timestamp;
        std::shared_ptr<int64_t> media_type;
        std::shared_ptr<std::string> code;
        std::shared_ptr<std::string> client_cache_key;
        std::shared_ptr<int64_t> filter_type;
        std::shared_ptr<bool> is_unified_video;
        std::shared_ptr<bool> should_request_ads;
        std::shared_ptr<UserFeed> user;
        std::shared_ptr<bool> can_viewer_reshare;
        std::shared_ptr<bool> caption_is_edited;
        std::shared_ptr<bool> like_and_view_counts_disabled;
        std::shared_ptr<LikerConfig> liker_config;
        std::shared_ptr<bool> is_commercial;
        std::shared_ptr<std::string> commerciality_status;
        std::shared_ptr<bool> is_paid_partnership;
        std::shared_ptr<bool> comment_likes_enabled;
        std::shared_ptr<bool> comment_threading_enabled;
        std::shared_ptr<bool> has_more_comments;
        std::shared_ptr<int64_t> max_num_visible_preview_comments;
        std::shared_ptr<std::vector<nlohmann::json>> preview_comments;
        std::shared_ptr<bool> can_view_more_preview_comments;
        std::shared_ptr<int64_t> comment_count;
        std::shared_ptr<bool> hide_view_all_comment_entrypoint;
        std::shared_ptr<std::string> inline_composer_display_condition;
        std::shared_ptr<ImageVersions2> image_versions2;
        std::shared_ptr<int64_t> original_width;
        std::shared_ptr<int64_t> original_height;
        std::shared_ptr<int64_t> like_count;
        std::shared_ptr<bool> has_liked;
        std::shared_ptr<std::vector<std::string>> top_likers;
        std::shared_ptr<bool> photo_of_you;
        std::shared_ptr<bool> can_see_insights_as_brand;
        nlohmann::json caption;
        std::shared_ptr<bool> can_viewer_save;
        std::shared_ptr<std::string> organic_tracking_token;
        std::shared_ptr<SharingFrictionInfo> sharing_friction_info;
        std::shared_ptr<std::string> product_type;
        std::shared_ptr<bool> is_in_profile_grid;
        std::shared_ptr<bool> profile_grid_control_enabled;
        std::shared_ptr<int64_t> deleted_reason;
        std::shared_ptr<std::string> integrity_review_decision;
        std::shared_ptr<std::vector<FacepileTopLiker>> facepile_top_likers;

        public:
        std::shared_ptr<int64_t> get_taken_at() const { return taken_at; }
        void set_taken_at(std::shared_ptr<int64_t> value) { this->taken_at = value; }

        std::shared_ptr<double> get_pk() const { return pk; }
        void set_pk(std::shared_ptr<double> value) { this->pk = value; }

        std::shared_ptr<std::string> get_id() const { return id; }
        void set_id(std::shared_ptr<std::string> value) { this->id = value; }

        std::shared_ptr<int64_t> get_device_timestamp() const { return device_timestamp; }
        void set_device_timestamp(std::shared_ptr<int64_t> value) { this->device_timestamp = value; }

        std::shared_ptr<int64_t> get_media_type() const { return media_type; }
        void set_media_type(std::shared_ptr<int64_t> value) { this->media_type = value; }

        std::shared_ptr<std::string> get_code() const { return code; }
        void set_code(std::shared_ptr<std::string> value) { this->code = value; }

        std::shared_ptr<std::string> get_client_cache_key() const { return client_cache_key; }
        void set_client_cache_key(std::shared_ptr<std::string> value) { this->client_cache_key = value; }

        std::shared_ptr<int64_t> get_filter_type() const { return filter_type; }
        void set_filter_type(std::shared_ptr<int64_t> value) { this->filter_type = value; }

        std::shared_ptr<bool> get_is_unified_video() const { return is_unified_video; }
        void set_is_unified_video(std::shared_ptr<bool> value) { this->is_unified_video = value; }

        std::shared_ptr<bool> get_should_request_ads() const { return should_request_ads; }
        void set_should_request_ads(std::shared_ptr<bool> value) { this->should_request_ads = value; }

        std::shared_ptr<UserFeed> get_user() const { return user; }
        void set_user(std::shared_ptr<UserFeed> value) { this->user = value; }

        std::shared_ptr<bool> get_can_viewer_reshare() const { return can_viewer_reshare; }
        void set_can_viewer_reshare(std::shared_ptr<bool> value) { this->can_viewer_reshare = value; }

        std::shared_ptr<bool> get_caption_is_edited() const { return caption_is_edited; }
        void set_caption_is_edited(std::shared_ptr<bool> value) { this->caption_is_edited = value; }

        std::shared_ptr<bool> get_like_and_view_counts_disabled() const { return like_and_view_counts_disabled; }
        void set_like_and_view_counts_disabled(std::shared_ptr<bool> value) { this->like_and_view_counts_disabled = value; }

        std::shared_ptr<LikerConfig> get_liker_config() const { return liker_config; }
        void set_liker_config(std::shared_ptr<LikerConfig> value) { this->liker_config = value; }

        std::shared_ptr<bool> get_is_commercial() const { return is_commercial; }
        void set_is_commercial(std::shared_ptr<bool> value) { this->is_commercial = value; }

        std::shared_ptr<std::string> get_commerciality_status() const { return commerciality_status; }
        void set_commerciality_status(std::shared_ptr<std::string> value) { this->commerciality_status = value; }

        std::shared_ptr<bool> get_is_paid_partnership() const { return is_paid_partnership; }
        void set_is_paid_partnership(std::shared_ptr<bool> value) { this->is_paid_partnership = value; }

        std::shared_ptr<bool> get_comment_likes_enabled() const { return comment_likes_enabled; }
        void set_comment_likes_enabled(std::shared_ptr<bool> value) { this->comment_likes_enabled = value; }

        std::shared_ptr<bool> get_comment_threading_enabled() const { return comment_threading_enabled; }
        void set_comment_threading_enabled(std::shared_ptr<bool> value) { this->comment_threading_enabled = value; }

        std::shared_ptr<bool> get_has_more_comments() const { return has_more_comments; }
        void set_has_more_comments(std::shared_ptr<bool> value) { this->has_more_comments = value; }

        std::shared_ptr<int64_t> get_max_num_visible_preview_comments() const { return max_num_visible_preview_comments; }
        void set_max_num_visible_preview_comments(std::shared_ptr<int64_t> value) { this->max_num_visible_preview_comments = value; }

        std::shared_ptr<std::vector<nlohmann::json>> get_preview_comments() const { return preview_comments; }
        void set_preview_comments(std::shared_ptr<std::vector<nlohmann::json>> value) { this->preview_comments = value; }

        std::shared_ptr<bool> get_can_view_more_preview_comments() const { return can_view_more_preview_comments; }
        void set_can_view_more_preview_comments(std::shared_ptr<bool> value) { this->can_view_more_preview_comments = value; }

        std::shared_ptr<int64_t> get_comment_count() const { return comment_count; }
        void set_comment_count(std::shared_ptr<int64_t> value) { this->comment_count = value; }

        std::shared_ptr<bool> get_hide_view_all_comment_entrypoint() const { return hide_view_all_comment_entrypoint; }
        void set_hide_view_all_comment_entrypoint(std::shared_ptr<bool> value) { this->hide_view_all_comment_entrypoint = value; }

        std::shared_ptr<std::string> get_inline_composer_display_condition() const { return inline_composer_display_condition; }
        void set_inline_composer_display_condition(std::shared_ptr<std::string> value) { this->inline_composer_display_condition = value; }

        std::shared_ptr<ImageVersions2> get_image_versions2() const { return image_versions2; }
        void set_image_versions2(std::shared_ptr<ImageVersions2> value) { this->image_versions2 = value; }

        std::shared_ptr<int64_t> get_original_width() const { return original_width; }
        void set_original_width(std::shared_ptr<int64_t> value) { this->original_width = value; }

        std::shared_ptr<int64_t> get_original_height() const { return original_height; }
        void set_original_height(std::shared_ptr<int64_t> value) { this->original_height = value; }

        std::shared_ptr<int64_t> get_like_count() const { return like_count; }
        void set_like_count(std::shared_ptr<int64_t> value) { this->like_count = value; }

        std::shared_ptr<bool> get_has_liked() const { return has_liked; }
        void set_has_liked(std::shared_ptr<bool> value) { this->has_liked = value; }

        std::shared_ptr<std::vector<std::string>> get_top_likers() const { return top_likers; }
        void set_top_likers(std::shared_ptr<std::vector<std::string>> value) { this->top_likers = value; }

        std::shared_ptr<bool> get_photo_of_you() const { return photo_of_you; }
        void set_photo_of_you(std::shared_ptr<bool> value) { this->photo_of_you = value; }

        std::shared_ptr<bool> get_can_see_insights_as_brand() const { return can_see_insights_as_brand; }
        void set_can_see_insights_as_brand(std::shared_ptr<bool> value) { this->can_see_insights_as_brand = value; }

        const nlohmann::json & get_caption() const { return caption; }
        nlohmann::json & get_mutable_caption() { return caption; }
        void set_caption(const nlohmann::json & value) { this->caption = value; }

        std::shared_ptr<bool> get_can_viewer_save() const { return can_viewer_save; }
        void set_can_viewer_save(std::shared_ptr<bool> value) { this->can_viewer_save = value; }

        std::shared_ptr<std::string> get_organic_tracking_token() const { return organic_tracking_token; }
        void set_organic_tracking_token(std::shared_ptr<std::string> value) { this->organic_tracking_token = value; }

        std::shared_ptr<SharingFrictionInfo> get_sharing_friction_info() const { return sharing_friction_info; }
        void set_sharing_friction_info(std::shared_ptr<SharingFrictionInfo> value) { this->sharing_friction_info = value; }

        std::shared_ptr<std::string> get_product_type() const { return product_type; }
        void set_product_type(std::shared_ptr<std::string> value) { this->product_type = value; }

        std::shared_ptr<bool> get_is_in_profile_grid() const { return is_in_profile_grid; }
        void set_is_in_profile_grid(std::shared_ptr<bool> value) { this->is_in_profile_grid = value; }

        std::shared_ptr<bool> get_profile_grid_control_enabled() const { return profile_grid_control_enabled; }
        void set_profile_grid_control_enabled(std::shared_ptr<bool> value) { this->profile_grid_control_enabled = value; }

        std::shared_ptr<int64_t> get_deleted_reason() const { return deleted_reason; }
        void set_deleted_reason(std::shared_ptr<int64_t> value) { this->deleted_reason = value; }

        std::shared_ptr<std::string> get_integrity_review_decision() const { return integrity_review_decision; }
        void set_integrity_review_decision(std::shared_ptr<std::string> value) { this->integrity_review_decision = value; }

        std::shared_ptr<std::vector<FacepileTopLiker>> get_facepile_top_likers() const { return facepile_top_likers; }
        void set_facepile_top_likers(std::shared_ptr<std::vector<FacepileTopLiker>> value) { this->facepile_top_likers = value; }
    };

    class UserFeedRequest {
        public:
        UserFeedRequest() = default;
        virtual ~UserFeedRequest() = default;

        private:
        std::shared_ptr<std::vector<Item>> items;
        std::shared_ptr<int64_t> num_results;
        std::shared_ptr<bool> more_available;
        std::shared_ptr<bool> auto_load_more_enabled;
        std::shared_ptr<std::string> status;

        public:
        std::shared_ptr<std::vector<Item>> get_items() const { return items; }
        void set_items(std::shared_ptr<std::vector<Item>> value) { this->items = value; }

        std::shared_ptr<int64_t> get_num_results() const { return num_results; }
        void set_num_results(std::shared_ptr<int64_t> value) { this->num_results = value; }

        std::shared_ptr<bool> get_more_available() const { return more_available; }
        void set_more_available(std::shared_ptr<bool> value) { this->more_available = value; }

        std::shared_ptr<bool> get_auto_load_more_enabled() const { return auto_load_more_enabled; }
        void set_auto_load_more_enabled(std::shared_ptr<bool> value) { this->auto_load_more_enabled = value; }

        std::shared_ptr<std::string> get_status() const { return status; }
        void set_status(std::shared_ptr<std::string> value) { this->status = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, IgTypes::FacepileTopLiker & x);
    void to_json(json & j, const IgTypes::FacepileTopLiker & x);

    void from_json(const json & j, IgTypes::Candidate & x);
    void to_json(json & j, const IgTypes::Candidate & x);

    void from_json(const json & j, IgTypes::ImageVersions2 & x);
    void to_json(json & j, const IgTypes::ImageVersions2 & x);

    void from_json(const json & j, IgTypes::LikerConfig & x);
    void to_json(json & j, const IgTypes::LikerConfig & x);

    void from_json(const json & j, IgTypes::SharingFrictionInfo & x);
    void to_json(json & j, const IgTypes::SharingFrictionInfo & x);

    void from_json(const json & j, IgTypes::UserFeed & x);
    void to_json(json & j, const IgTypes::UserFeed & x);

    void from_json(const json & j, IgTypes::Item & x);
    void to_json(json & j, const IgTypes::Item & x);

    void from_json(const json & j, IgTypes::UserFeedRequest & x);
    void to_json(json & j, const IgTypes::UserFeedRequest & x);

    inline void from_json(const json & j, IgTypes::FacepileTopLiker& x) {
        x.set_pk(IgTypes::get_optional<int64_t>(j, "pk"));
        x.set_username(IgTypes::get_optional<std::string>(j, "username"));
        x.set_full_name(IgTypes::get_optional<std::string>(j, "full_name"));
        x.set_is_private(IgTypes::get_optional<bool>(j, "is_private"));
        x.set_profile_pic_url(IgTypes::get_optional<std::string>(j, "profile_pic_url"));
        x.set_profile_pic_id(IgTypes::get_optional<std::string>(j, "profile_pic_id"));
        x.set_is_verified(IgTypes::get_optional<bool>(j, "is_verified"));
        x.set_follow_friction_type(IgTypes::get_optional<int64_t>(j, "follow_friction_type"));
    }

    inline void to_json(json & j, const IgTypes::FacepileTopLiker & x) {
        j = json::object();
        j["pk"] = x.get_pk();
        j["username"] = x.get_username();
        j["full_name"] = x.get_full_name();
        j["is_private"] = x.get_is_private();
        j["profile_pic_url"] = x.get_profile_pic_url();
        j["profile_pic_id"] = x.get_profile_pic_id();
        j["is_verified"] = x.get_is_verified();
        j["follow_friction_type"] = x.get_follow_friction_type();
    }

    inline void from_json(const json & j, IgTypes::Candidate& x) {
        x.set_width(IgTypes::get_optional<int64_t>(j, "width"));
        x.set_height(IgTypes::get_optional<int64_t>(j, "height"));
        x.set_url(IgTypes::get_optional<std::string>(j, "url"));
        x.set_scans_profile(IgTypes::get_optional<std::string>(j, "scans_profile"));
        x.set_estimated_scans_sizes(IgTypes::get_optional<std::vector<int64_t>>(j, "estimated_scans_sizes"));
    }

    inline void to_json(json & j, const IgTypes::Candidate & x) {
        j = json::object();
        j["width"] = x.get_width();
        j["height"] = x.get_height();
        j["url"] = x.get_url();
        j["scans_profile"] = x.get_scans_profile();
        j["estimated_scans_sizes"] = x.get_estimated_scans_sizes();
    }

    inline void from_json(const json & j, IgTypes::ImageVersions2& x) {
        x.set_candidates(IgTypes::get_optional<std::vector<IgTypes::Candidate>>(j, "candidates"));
    }

    inline void to_json(json & j, const IgTypes::ImageVersions2 & x) {
        j = json::object();
        j["candidates"] = x.get_candidates();
    }

    inline void from_json(const json & j, IgTypes::LikerConfig& x) {
        x.set_is_daisy(IgTypes::get_optional<bool>(j, "is_daisy"));
        x.set_hide_view_count(IgTypes::get_optional<bool>(j, "hide_view_count"));
        x.set_show_count_in_likers_list(IgTypes::get_optional<bool>(j, "show_count_in_likers_list"));
        x.set_show_view_count_in_likers_list(IgTypes::get_optional<bool>(j, "show_view_count_in_likers_list"));
        x.set_show_daisy_liker_list_header(IgTypes::get_optional<bool>(j, "show_daisy_liker_list_header"));
        x.set_show_learn_more(IgTypes::get_optional<bool>(j, "show_learn_more"));
        x.set_ads_display_mode(IgTypes::get_optional<int64_t>(j, "ads_display_mode"));
        x.set_display_mode(IgTypes::get_optional<int64_t>(j, "display_mode"));
        x.set_disable_liker_list_navigation(IgTypes::get_optional<bool>(j, "disable_liker_list_navigation"));
        x.set_show_author_view_likes_button(IgTypes::get_optional<bool>(j, "show_author_view_likes_button"));
        x.set_is_in_daisy_controls(IgTypes::get_optional<bool>(j, "is_in_daisy_controls"));
    }

    inline void to_json(json & j, const IgTypes::LikerConfig & x) {
        j = json::object();
        j["is_daisy"] = x.get_is_daisy();
        j["hide_view_count"] = x.get_hide_view_count();
        j["show_count_in_likers_list"] = x.get_show_count_in_likers_list();
        j["show_view_count_in_likers_list"] = x.get_show_view_count_in_likers_list();
        j["show_daisy_liker_list_header"] = x.get_show_daisy_liker_list_header();
        j["show_learn_more"] = x.get_show_learn_more();
        j["ads_display_mode"] = x.get_ads_display_mode();
        j["display_mode"] = x.get_display_mode();
        j["disable_liker_list_navigation"] = x.get_disable_liker_list_navigation();
        j["show_author_view_likes_button"] = x.get_show_author_view_likes_button();
        j["is_in_daisy_controls"] = x.get_is_in_daisy_controls();
    }

    inline void from_json(const json & j, IgTypes::SharingFrictionInfo& x) {
        x.set_should_have_sharing_friction(IgTypes::get_optional<bool>(j, "should_have_sharing_friction"));
        x.set_bloks_app_url(IgTypes::get_untyped(j, "bloks_app_url"));
    }

    inline void to_json(json & j, const IgTypes::SharingFrictionInfo & x) {
        j = json::object();
        j["should_have_sharing_friction"] = x.get_should_have_sharing_friction();
        j["bloks_app_url"] = x.get_bloks_app_url();
    }

    inline void from_json(const json & j, IgTypes::UserFeed& x) {
        x.set_pk(IgTypes::get_optional<int64_t>(j, "pk"));
        x.set_username(IgTypes::get_optional<std::string>(j, "username"));
        x.set_full_name(IgTypes::get_optional<std::string>(j, "full_name"));
        x.set_is_private(IgTypes::get_optional<bool>(j, "is_private"));
        x.set_profile_pic_url(IgTypes::get_optional<std::string>(j, "profile_pic_url"));
        x.set_is_verified(IgTypes::get_optional<bool>(j, "is_verified"));
        x.set_follow_friction_type(IgTypes::get_optional<int64_t>(j, "follow_friction_type"));
        x.set_has_anonymous_profile_picture(IgTypes::get_optional<bool>(j, "has_anonymous_profile_picture"));
        x.set_is_unpublished(IgTypes::get_optional<bool>(j, "is_unpublished"));
        x.set_is_favorite(IgTypes::get_optional<bool>(j, "is_favorite"));
        x.set_account_badges(IgTypes::get_optional<std::vector<json>>(j, "account_badges"));
        x.set_latest_reel_media(IgTypes::get_optional<int64_t>(j, "latest_reel_media"));
    }

    inline void to_json(json & j, const IgTypes::UserFeed & x) {
        j = json::object();
        j["pk"] = x.get_pk();
        j["username"] = x.get_username();
        j["full_name"] = x.get_full_name();
        j["is_private"] = x.get_is_private();
        j["profile_pic_url"] = x.get_profile_pic_url();
        j["is_verified"] = x.get_is_verified();
        j["follow_friction_type"] = x.get_follow_friction_type();
        j["has_anonymous_profile_picture"] = x.get_has_anonymous_profile_picture();
        j["is_unpublished"] = x.get_is_unpublished();
        j["is_favorite"] = x.get_is_favorite();
        j["account_badges"] = x.get_account_badges();
        j["latest_reel_media"] = x.get_latest_reel_media();
    }

    inline void from_json(const json & j, IgTypes::Item& x) {
        x.set_taken_at(IgTypes::get_optional<int64_t>(j, "taken_at"));
        x.set_pk(IgTypes::get_optional<double>(j, "pk"));
        x.set_id(IgTypes::get_optional<std::string>(j, "id"));
        x.set_device_timestamp(IgTypes::get_optional<int64_t>(j, "device_timestamp"));
        x.set_media_type(IgTypes::get_optional<int64_t>(j, "media_type"));
        x.set_code(IgTypes::get_optional<std::string>(j, "code"));
        x.set_client_cache_key(IgTypes::get_optional<std::string>(j, "client_cache_key"));
        x.set_filter_type(IgTypes::get_optional<int64_t>(j, "filter_type"));
        x.set_is_unified_video(IgTypes::get_optional<bool>(j, "is_unified_video"));
        x.set_should_request_ads(IgTypes::get_optional<bool>(j, "should_request_ads"));
        x.set_user(IgTypes::get_optional<IgTypes::UserFeed>(j, "user"));
        x.set_can_viewer_reshare(IgTypes::get_optional<bool>(j, "can_viewer_reshare"));
        x.set_caption_is_edited(IgTypes::get_optional<bool>(j, "caption_is_edited"));
        x.set_like_and_view_counts_disabled(IgTypes::get_optional<bool>(j, "like_and_view_counts_disabled"));
        x.set_liker_config(IgTypes::get_optional<IgTypes::LikerConfig>(j, "liker_config"));
        x.set_is_commercial(IgTypes::get_optional<bool>(j, "is_commercial"));
        x.set_commerciality_status(IgTypes::get_optional<std::string>(j, "commerciality_status"));
        x.set_is_paid_partnership(IgTypes::get_optional<bool>(j, "is_paid_partnership"));
        x.set_comment_likes_enabled(IgTypes::get_optional<bool>(j, "comment_likes_enabled"));
        x.set_comment_threading_enabled(IgTypes::get_optional<bool>(j, "comment_threading_enabled"));
        x.set_has_more_comments(IgTypes::get_optional<bool>(j, "has_more_comments"));
        x.set_max_num_visible_preview_comments(IgTypes::get_optional<int64_t>(j, "max_num_visible_preview_comments"));
        x.set_preview_comments(IgTypes::get_optional<std::vector<json>>(j, "preview_comments"));
        x.set_can_view_more_preview_comments(IgTypes::get_optional<bool>(j, "can_view_more_preview_comments"));
        x.set_comment_count(IgTypes::get_optional<int64_t>(j, "comment_count"));
        x.set_hide_view_all_comment_entrypoint(IgTypes::get_optional<bool>(j, "hide_view_all_comment_entrypoint"));
        x.set_inline_composer_display_condition(IgTypes::get_optional<std::string>(j, "inline_composer_display_condition"));
        x.set_image_versions2(IgTypes::get_optional<IgTypes::ImageVersions2>(j, "image_versions2"));
        x.set_original_width(IgTypes::get_optional<int64_t>(j, "original_width"));
        x.set_original_height(IgTypes::get_optional<int64_t>(j, "original_height"));
        x.set_like_count(IgTypes::get_optional<int64_t>(j, "like_count"));
        x.set_has_liked(IgTypes::get_optional<bool>(j, "has_liked"));
        x.set_top_likers(IgTypes::get_optional<std::vector<std::string>>(j, "top_likers"));
        x.set_photo_of_you(IgTypes::get_optional<bool>(j, "photo_of_you"));
        x.set_can_see_insights_as_brand(IgTypes::get_optional<bool>(j, "can_see_insights_as_brand"));
        x.set_caption(IgTypes::get_untyped(j, "caption"));
        x.set_can_viewer_save(IgTypes::get_optional<bool>(j, "can_viewer_save"));
        x.set_organic_tracking_token(IgTypes::get_optional<std::string>(j, "organic_tracking_token"));
        x.set_sharing_friction_info(IgTypes::get_optional<IgTypes::SharingFrictionInfo>(j, "sharing_friction_info"));
        x.set_product_type(IgTypes::get_optional<std::string>(j, "product_type"));
        x.set_is_in_profile_grid(IgTypes::get_optional<bool>(j, "is_in_profile_grid"));
        x.set_profile_grid_control_enabled(IgTypes::get_optional<bool>(j, "profile_grid_control_enabled"));
        x.set_deleted_reason(IgTypes::get_optional<int64_t>(j, "deleted_reason"));
        x.set_integrity_review_decision(IgTypes::get_optional<std::string>(j, "integrity_review_decision"));
        x.set_facepile_top_likers(IgTypes::get_optional<std::vector<IgTypes::FacepileTopLiker>>(j, "facepile_top_likers"));
    }

    inline void to_json(json & j, const IgTypes::Item & x) {
        j = json::object();
        j["taken_at"] = x.get_taken_at();
        j["pk"] = x.get_pk();
        j["id"] = x.get_id();
        j["device_timestamp"] = x.get_device_timestamp();
        j["media_type"] = x.get_media_type();
        j["code"] = x.get_code();
        j["client_cache_key"] = x.get_client_cache_key();
        j["filter_type"] = x.get_filter_type();
        j["is_unified_video"] = x.get_is_unified_video();
        j["should_request_ads"] = x.get_should_request_ads();
        j["user"] = x.get_user();
        j["can_viewer_reshare"] = x.get_can_viewer_reshare();
        j["caption_is_edited"] = x.get_caption_is_edited();
        j["like_and_view_counts_disabled"] = x.get_like_and_view_counts_disabled();
        j["liker_config"] = x.get_liker_config();
        j["is_commercial"] = x.get_is_commercial();
        j["commerciality_status"] = x.get_commerciality_status();
        j["is_paid_partnership"] = x.get_is_paid_partnership();
        j["comment_likes_enabled"] = x.get_comment_likes_enabled();
        j["comment_threading_enabled"] = x.get_comment_threading_enabled();
        j["has_more_comments"] = x.get_has_more_comments();
        j["max_num_visible_preview_comments"] = x.get_max_num_visible_preview_comments();
        j["preview_comments"] = x.get_preview_comments();
        j["can_view_more_preview_comments"] = x.get_can_view_more_preview_comments();
        j["comment_count"] = x.get_comment_count();
        j["hide_view_all_comment_entrypoint"] = x.get_hide_view_all_comment_entrypoint();
        j["inline_composer_display_condition"] = x.get_inline_composer_display_condition();
        j["image_versions2"] = x.get_image_versions2();
        j["original_width"] = x.get_original_width();
        j["original_height"] = x.get_original_height();
        j["like_count"] = x.get_like_count();
        j["has_liked"] = x.get_has_liked();
        j["top_likers"] = x.get_top_likers();
        j["photo_of_you"] = x.get_photo_of_you();
        j["can_see_insights_as_brand"] = x.get_can_see_insights_as_brand();
        j["caption"] = x.get_caption();
        j["can_viewer_save"] = x.get_can_viewer_save();
        j["organic_tracking_token"] = x.get_organic_tracking_token();
        j["sharing_friction_info"] = x.get_sharing_friction_info();
        j["product_type"] = x.get_product_type();
        j["is_in_profile_grid"] = x.get_is_in_profile_grid();
        j["profile_grid_control_enabled"] = x.get_profile_grid_control_enabled();
        j["deleted_reason"] = x.get_deleted_reason();
        j["integrity_review_decision"] = x.get_integrity_review_decision();
        j["facepile_top_likers"] = x.get_facepile_top_likers();
    }

    inline void from_json(const json & j, IgTypes::UserFeedRequest& x) {
        x.set_items(IgTypes::get_optional<std::vector<IgTypes::Item>>(j, "items"));
        x.set_num_results(IgTypes::get_optional<int64_t>(j, "num_results"));
        x.set_more_available(IgTypes::get_optional<bool>(j, "more_available"));
        x.set_auto_load_more_enabled(IgTypes::get_optional<bool>(j, "auto_load_more_enabled"));
        x.set_status(IgTypes::get_optional<std::string>(j, "status"));
    }

    inline void to_json(json & j, const IgTypes::UserFeedRequest & x) {
        j = json::object();
        j["items"] = x.get_items();
        j["num_results"] = x.get_num_results();
        j["more_available"] = x.get_more_available();
        j["auto_load_more_enabled"] = x.get_auto_load_more_enabled();
        j["status"] = x.get_status();
    }
}
