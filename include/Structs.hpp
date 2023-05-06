#include <iostream>
#include <string>
#include <ctime>
/*
    A sample using json_dto
*/
struct message_t
{
    message_t() {}

    message_t(
        std::string from,
        std::int64_t when,
        std::string text)
        : m_from{std::move(from)}, m_when{when}, m_text{std::move(text)}
    {
    }

    // Who sent a message.
    std::string m_from;
    // When the message was sent (unixtime).
    std::int64_t m_when;
    // Message text.
    std::string m_text;

    template <typename Json_Io>
    void json_io(Json_Io &io)
    {
        io &json_dto::mandatory("from", m_from) & json_dto::mandatory("when", m_when) & json_dto::mandatory("text", m_text);
    }
};
struct polygonPoint_t
{
    polygonPoint_t() {}
    polygonPoint_t(double length,
                   double width,
                   double height) : m_length{length},
                                    m_width{width},
                                    m_height{height} {}
    double m_length;
    double m_width;
    double m_height;
    template <typename Json_Io>

    void json_io(Json_Io &io)
    {
        io &
                json_dto::mandatory("length", m_length) &
            json_dto::mandatory("width", m_width) &
            json_dto::mandatory("height", m_height);
    }
};
// struct pathHistory_t
// {
// };
// struct pathPlanning_t
// {
// };
struct participantBody_t
{
    participantBody_t() {}
    participantBody_t(
        std::int64_t timestamp,
        std::int8_t ptcType,
        std::int32_t ptcId,
        std::int8_t vehicleClass,
        std::int8_t vehicleStatus,
        std::int8_t sourceType,
        std::int32_t crossId,
        std::int8_t crossType,
        std::string crossName,
        std::string linkName,
        std::int32_t linkId,
        std::int32_t laneId,
        double longitude,
        double latitude,
        double elevation,
        std::int8_t positionConfidence,
        std::int8_t status,
        double speed,
        std::int8_t speedConfidence,
        double heading,
        std::int8_t headingConfidence,
        double acceleration,
        std::int8_t accelerationConfidence,
        double length,
        double width,
        double height,
        // std::vector<polygonPoint_t> polygonPoint,
        std::int8_t tracking,
        // std::vector<pathHistory_t> pathHistory,
        // std::vector<pathPlanning_t> pathPlanning,
        std::string colour,
        std::string license,
        std::string brand) : // 时间戳，必填
                             m_timestamp{timestamp},
                             // 交通参与者类型，必填
                             m_ptcType{ptcType},
                             // 交通参与者编号，必填
                             m_ptcId{ptcId},
                             // 车辆类型
                             m_vehicleClass{vehicleClass},
                             // 车辆状态
                             m_vehicleStatus{vehicleStatus},
                             // 来源
                             m_sourceType{sourceType},
                             // 路口编号
                             m_crossId{crossId},
                             // 路口类型
                             m_crossType{crossType},
                             // 路口名称
                             m_crossName{crossName},
                             // 路段名称
                             m_linkName{linkName},
                             // 路段编号
                             m_linkId{linkId},
                             // 所在车道
                             m_laneId{laneId},
                             // 经度，必填
                             m_longitude{longitude},
                             // 维度，必填
                             m_latitude{latitude},
                             // 海拔
                             m_elevation{elevation},
                             // 车辆位置置信度
                             m_positionConfidence{positionConfidence},
                             // 交通参与者状态
                             m_status{status},
                             // 速度
                             m_speed{speed},
                             // 速度置信度
                             m_speedConfidence{speedConfidence},
                             // 航向角
                             m_heading{heading},
                             // 航向角置信度
                             m_headingConfidence{headingConfidence},
                             // 4轴加速度
                             m_acceleration{acceleration},
                             // 4轴加速度置信度
                             m_accelerationConfidence{accelerationConfidence},
                             // 长
                             m_length{length},
                             // 宽
                             m_width{width},
                             // 高
                             m_height{height},
                             // 长宽高有序点序列
                             //  m_polygonPoint{polygonPoint},
                             // 目标跟踪时长
                             m_tracking{tracking},
                             // 目标历史轨迹
                             //  m_pathHistory{pathHistory},
                             // 目标轨迹预测
                             //  m_pathPlanning{pathPlanning},
                             // 颜色
                             m_colour{colour},
                             // 车辆号牌
                             m_license{license},
                             // 车辆品牌
                             m_brand{brand}
    {
    }

    // 时间戳，必填
    std::int64_t m_timestamp;
    // 交通参与者类型，必填
    std::int8_t m_ptcType;
    // 交通参与者编号，必填
    std::int32_t m_ptcId;
    // 车辆类型
    std::int8_t m_vehicleClass;
    // 车辆状态
    std::int8_t m_vehicleStatus;
    // 来源
    std::int8_t m_sourceType;
    // 路口编号
    std::int32_t m_crossId;
    // 路口类型
    std::int8_t m_crossType;
    // 路口名称
    std::string m_crossName;
    // 路段名称
    std::string m_linkName;
    // 路段编号
    std::int32_t m_linkId;
    // 所在车道
    std::int32_t m_laneId;
    // 经度，必填
    double m_longitude;
    // 维度，必填
    double m_latitude;
    // 海拔
    double m_elevation;
    // 车辆位置置信度
    std::int8_t m_positionConfidence;
    // 交通参与者状态
    std::int8_t m_status;
    // 速度
    double m_speed;
    // 速度置信度
    std::int8_t m_speedConfidence;
    // 航向角
    double m_heading;
    // 航向角置信度
    std::int8_t m_headingConfidence;
    // 4轴加速度
    double m_acceleration;
    // 4轴加速度置信度
    std::int8_t m_accelerationConfidence;
    // 长
    double m_length;
    // 宽
    double m_width;
    // 高
    double m_height;
    // 长宽高有序点序列
    // std::vector<polygonPoint_t> m_polygonPoint;
    // 目标跟踪时长
    std::int8_t m_tracking;
    // 目标历史轨迹
    // std::vector<pathHistory_t> m_pathHistory;
    // 目标轨迹预测
    // std::vector<pathPlanning_t> m_pathPlanning;
    // 颜色
    std::string m_colour;
    // 车辆号牌
    std::string m_license;
    // 车辆品牌
    std::string m_brand;

    template <typename Json_Io>

    void json_io(Json_Io &io)
    {
        io &
                // 时间戳，必填
                json_dto::mandatory("timestamp", m_timestamp) &
            // 交通参与者类型，必填
            json_dto::mandatory("ptcType", m_ptcType) &
            // 交通参与者编号，必填
            json_dto::mandatory("ptcId", m_ptcId) &
            // 车辆类型
            json_dto::mandatory("vehicleClass", m_vehicleClass) &
            // 车辆状态
            json_dto::mandatory("vehicleStatus", m_vehicleStatus) &
            // 来源
            json_dto::mandatory("sourceType", m_sourceType) &
            // 路口编号
            json_dto::mandatory("crossId", m_crossId) &
            // 路口类型
            json_dto::mandatory("crossType", m_crossType) &
            // 路口名称
            json_dto::mandatory("crossName", m_crossName) &
            // 路段名称
            json_dto::mandatory("linkName", m_linkName) &
            // 路段编号
            json_dto::mandatory("linkId", m_linkId) &
            // 所在车道
            json_dto::mandatory("laneId", m_laneId) &
            // 经度，必填
            json_dto::mandatory("longitude", m_longitude) &
            // 维度，必填
            json_dto::mandatory("latitude", m_latitude) &
            // 海拔
            json_dto::mandatory("elevation", m_elevation) &
            // 车辆位置置信度
            json_dto::mandatory("positionConfidence", m_positionConfidence) &
            // 交通参与者状态
            json_dto::mandatory("status", m_status) &
            // 速度
            json_dto::mandatory("speed", m_speed) &
            // 速度置信度
            json_dto::mandatory("speedConfidence", m_speedConfidence) &
            // 航向角
            json_dto::mandatory("heading", m_heading) &
            // 航向角置信度
            json_dto::mandatory("headingConfidence", m_headingConfidence) &
            // 4轴加速度
            json_dto::mandatory("acceleration", m_acceleration) &
            // 4轴加速度置信度
            json_dto::mandatory("accelerationConfidence", m_accelerationConfidence) &
            // 长
            json_dto::mandatory("length", m_length) &
            // 宽
            json_dto::mandatory("width", m_width) &
            // 高
            json_dto::mandatory("height", m_height) &
            // 长宽高有序点序列
            // json_dto::mandatory("polygonPoint", m_polygonPoint) &
            // 目标跟踪时长
            json_dto::mandatory("tracking", m_tracking) &
            // 目标历史轨迹
            // json_dto::mandatory("pathHistory", m_pathHistory) &
            // 目标轨迹预测
            // json_dto::mandatory("pathPlanning", m_pathPlanning) &
            // 颜色
            json_dto::mandatory("colour", m_colour) &
            // 车辆号牌
            json_dto::mandatory("license", m_license) &
            // 车辆品牌
            json_dto::mandatory("brand", m_brand);
    }
};

struct participant_t
{
    participant_t() {}
    participant_t(
        // std::string code,
        // std::string messageId,
        // std::string deviceId,
        std::int64_t timeStamp,
        std::string rscuSn,
        std::vector<participantBody_t> ptcList,
        bool ack) : //   m_code{std::move(code)},
                    //   m_messageId{std::move(messageId)},
                    //   m_deviceId{std::move(deviceId)},
                    m_timeStamp{timeStamp},
                    m_rscuSn{std::move(rscuSn)},
                    m_ptcList{ptcList},
                    m_ack{ack}
    {
    }

    // std::string m_code;
    // std::string m_messageId;
    // 设备id
    // std::string m_deviceId;
    // 时间戳，必填
    std::int64_t m_timeStamp;
    // RSCU的序列号，必填
    std::string m_rscuSn;
    // 交通参与者列表
    std::vector<participantBody_t> m_ptcList;
    // 是否需要确认，true是需要，false为不需要
    bool m_ack;

    template <typename Json_Io>

    void json_io(Json_Io &io)
    {
        io &
                // json_dto::mandatory("code", m_code) &
                // json_dto::mandatory("messageId", m_messageId) &
                // json_dto::mandatory("deviceId", m_deviceId) &
                json_dto::mandatory("timeStamp", m_timeStamp) &
            json_dto::mandatory("rscuSn", m_rscuSn) &
            json_dto::mandatory("ptcList", m_ptcList) &
            json_dto::mandatory("ack", m_ack);
    }
};
