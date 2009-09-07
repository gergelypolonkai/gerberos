/* Gerberos - Kerberos GLib bindings
 *
 * Copyright (C) 2009 Gergely Polonkai
 *
 */

#if !defined (__GERBEROS_GERBEROS_H_INSIDE__) && !defined (GERBEROS_COMPILATION)
# error "Only <gerberos/gerberos.h> can be included directly."
#endif

#ifndef __G_KRB5_CONTEXT_H__
#define __G_KRB5_CONTEXT_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define G_TYPE_KRB5_CONTEXT         (g_krb5_context_get_type ())
#define G_KRB5_CONTEXT(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), G_TYPE_KRB5_CONTEXT, GKrb5Context))
#define G_KRB5_CONTEXT_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), G_TYPE_KRB5_CONTEXT, GKrb5ContextClass))
#define G_IS_KRB5_CONTEXT(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), G_TYPE_KRB5_CONTEXT))
#define G_IS_KRB5_CONTEXT_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), G_TYPE_KRB5_CONTEXT))
#define G_KRB5_CONTEXT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), G_TYPE_KRB5_CONTEXT, GKrb5ContextClass))

typedef struct _GKrb5Context        GKrb5Context;
typedef struct _GKrb5ContextClass   GKrb5ContextClass;
typedef struct _GKrb5ContextPrivate GKrb5ContextPrivate;

/**
 * GKrb5Context
 *
 * Manages krb5_contexts (per process state)
 **/
struct _GKrb5Context
{
	GObject parent_instance;

	/*< private >*/
	GKrb5ContextPrivate *priv;
};

struct _GKrb5ContextClass
{
	GObjectClass parent_class;

	/* Signals */

	/*< private >*/
	/* Padding for future expansion */
	void (*_g_reserved1) (void);
	void (*_g_reserved2) (void);
	void (*_g_reserved3) (void);
	void (*_g_reserved4) (void);
	void (*_g_reserved5) (void);
};

GType g_krb5_context_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* __G_KRB5_CONTEXT_H__ */
