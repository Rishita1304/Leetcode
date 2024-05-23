select p.product_name as product_name, sum(o.unit) as unit
from products p join orders o
using(product_id)
where year(order_date) = 2020 and month(order_date) = 2
group by p.product_id
having sum(o.unit) >= 100