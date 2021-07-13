#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lest;
	t_list	*dest;

	if (!f)
		return (NULL);
	lest = NULL;
	while (lst)
	{
		dest = ft_lstnew((*f)(lst->content));
		if (!dest)
		{
			ft_lstclear(&lest, del);
			return (NULL);
		}
		ft_lstadd_back(&lest, dest);
		lst = lst->next;
	}
	return (lest);
}
