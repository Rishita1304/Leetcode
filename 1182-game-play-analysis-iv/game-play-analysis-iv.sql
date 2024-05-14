SELECT ROUND(COUNT(distinct player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity),2) AS fraction
FROM activity
where (player_id, date_sub(event_date, interval 1 day)) in
(SELECT player_id, MIN(event_date) AS first_login FROM Activity GROUP BY player_id)