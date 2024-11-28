/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   env_create_ctx.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gasroman <gasroman@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/27 11:06:30 by gasroman		  #+#	#+#			 */
/*   Updated: 2024/11/27 11:30:12 by gasroman		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

// Función principal para inicializar el entorno
// int	env_create_ctx(t_env_ctx *ctx, char **env)
// {
// 	int					i;
// 	char				*key;
// 	char				*value;
// 	char				*equal_sign;
// 	t_key_value_pair	*new_pair;
// 	t_key_value_pair	*current;

// 	i = 0;
// 	while (env[i])
// 	{
// 		equal_sign = ft_strchr(env[i], '=');
// 		if (equal_sign)
// 		{
// 			*equal_sign = '\0';
// 			key = env[i];
// 			value = equal_sign + 1;
// 		}
// 		else
// 		{
// 			key = env[i];
// 			value = NULL;
// 		}
// 		new_pair = create_pair(key, value);
// 		if (!new_pair)
// 			return (ENV_ERR_MEM_ALLOC);
// 		if (equal_sign)
// 			*equal_sign = '=';
// 		if (!ctx->key_value_pair)
// 			ctx->key_value_pair = new_pair;
// 		else
// 		{
// 			current = ctx->key_value_pair;
// 			while (current->next)
// 				current = current->next;
// 			current->next = new_pair;
// 		}
// 		i++;
// 	}
// 	return (ENV_SUCCESS);
// }

int	env_create_ctx(t_env_ctx **ctx, char **env)
{
	int		i;
	int		ret;
	char	*equal_sign;

	i = 0;
	if (!ctx || !env)
		return (ENV_ERR_INVALID_INPUT);
	*ctx = ft_calloc(sizeof(t_env_ctx), 1);
	if (!*ctx)
		return (ENV_ERR_MEM_ALLOC);
	while (env[i])
	{
		equal_sign = ft_strchr(env[i], '=');
		*equal_sign = '\0';
		ret = env_add(*ctx, env[i], equal_sign + 1);
		*equal_sign = '=';
		if (ret != ENV_SUCCESS)
		{
			env_delete_ctx(*ctx);
			return (ret);
		}
		i++;
	}
	return (ENV_SUCCESS);
}
