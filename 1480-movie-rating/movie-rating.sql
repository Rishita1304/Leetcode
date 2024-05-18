# Write your MySQL query statement below
(
    select name as results
    from users join movierating using(user_id)
    group by name
    order by count(*) desc, name
    limit 1
)
union all
(
    select title as results
    from movies join movierating using(movie_id)
    where extract(year_month from created_at) = 202002
    group by title
    order by avg(rating) desc, title
    limit 1

)